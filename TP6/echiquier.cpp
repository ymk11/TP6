#include "echiquier.hpp"
#include "Roi.hpp"
#include "tour.hpp"
#include "cavalier.hpp"
#include "QLabel"



namespace ui {
    Echiquier::Echiquier(QWidget* parent) : QMainWindow(parent) {
        centralWidget = new QWidget();
        mainWindow = new QHBoxLayout(this);
        mainWindow->setSpacing(55);
        mainWindow->setContentsMargins(QMargins(15,15,50,15));
        setCentralWidget(centralWidget);
        centralWidget->setLayout(mainWindow);
        initializeBoard();
        initializeMenu();
    }

    void Echiquier::initializeBoard() { //initialiser l'UI
        using namespace chess;
        plateau_.resize(8);
        for (int i = 0; i < 8; ++i) {
            plateau_[i].resize(8);
        }

        setWindowTitle(" Chess Game");
        chessBoard = new QVBoxLayout() ;
        chessBoard->setSpacing(0);
        mainWindow->addLayout(chessBoard);
        for (int i = 0; i < 8; i++) {
            QHBoxLayout* hBoxLayout = new QHBoxLayout();
            hBoxLayout->setSpacing(0);

            for (int j = 0; j < 8; j++) {
                Couleur couleur = Couleur::Blanc;
                if ((j+i) % 2 == 0) {
                    couleur = Couleur::Noir;
                }
                plateau_[i][j] = std::make_unique<Case>(couleur,Position(i,j));
                plateau_[i][j]->setMinimumSize(140, 140);

                
                connect(plateau_[i][j].get(), &Case::caseClicked, this, &Echiquier::handleButtonClick);

                
                hBoxLayout->addWidget(plateau_[i][j].get());
            }
            chessBoard->addLayout(hBoxLayout);
        }
        //piece temporaire pour le tp6
        plateau_[3][4]->setPiece(std::make_unique<Roi>(Roi(Couleur::Blanc)), true);
        plateau_[6][2]->setPiece(std::make_unique<Roi>(Roi(Couleur::Noir)), true);
        plateau_[7][7]->setPiece(std::make_unique<Cavalier>(Cavalier(Couleur::Blanc)), true);
        plateau_[0][0]->setPiece(std::make_unique<Tour>(Tour(Couleur::Noir)), true);
        plateau_[1][0]->setPiece(std::make_unique<Tour>(Tour(Couleur::Noir)), true);
        plateau_[2][0]->setPiece(std::make_unique<Tour>(Tour(Couleur::Noir)), true);
        plateau_[3][0]->setPiece(std::make_unique<Tour>(Tour(Couleur::Noir)), true);
        plateau_[3][1]->setPiece(std::make_unique<Tour>(Tour(Couleur::Noir)), true);
    }

    void Echiquier::initializeMenu() {
        QVBoxLayout* menuBox = new QVBoxLayout();
        menuBox->setAlignment(Qt::AlignTop);

        QPushButton* startButton = new QPushButton("Start");
        menuBox->addWidget(startButton);
        startButton->setMinimumSize(200, 30);
        mainWindow->addLayout(menuBox);

        QVBoxLayout* labelBox = new QVBoxLayout();
        QLabel* label= new QLabel("Select starting board");
        labelBox->setAlignment(Qt::AlignCenter);
        labelBox->addWidget(label);
        menuBox->addLayout(labelBox);
        
    }

    chess::Case& Echiquier::getCase(const chess::Position& position) {
        return *plateau_[position.getX()][position.getY()];
    }

    void Echiquier::setCase(const chess::Position& position, std::unique_ptr<chess::Piece> piece) {
        getCase(position).setPiece(std::move(piece));
    }

    bool Echiquier::isEmptyCase(const chess::Position& position) {
        return getCase(position).getPieceInfo() == nullptr;

    }
    chess::Couleur Echiquier::getInverseColor(const chess::Couleur& color) {
        return (color == chess::Couleur::Blanc) ? chess::Couleur::Noir : chess::Couleur::Blanc;
    }
    chess::Position Echiquier::kingPosition(const chess::Couleur& color) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess::Position pos(i, j);
                if ((getCase(pos).getPieceInfo() != nullptr) && (getCase(pos).getPieceInfo()->getCouleur() == color)
                    && (getCase(pos).getPieceInfo()->getTypePiece() == chess::TypePiece::Roi)) {
                    return pos;
                }

            }
        }
 
    }
    
    bool Echiquier::isCheck(const chess::Couleur& color) {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getAllMovements(getInverseColor(color));
        bool val  = positions.find(kingPosition(color)) != positions.end();
        return val;
    }
    bool Echiquier::isCheckMate() {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getAllMovements(joueur_);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess::Position postion(i, j);
                if ((getCase(postion).getPieceInfo() != nullptr) && (getCase(postion).getPieceInfo()->getCouleur() == joueur_)) {
                    lastSelected = std::make_unique<chess::Position>(postion);
                    if (!getFilteredMovement().empty()) {
                        lastSelected = nullptr;
                        return false;
                    }
                }
            }
        }
        std::cout << "end!!!!!!!!!!!!!!";
        lastSelected = nullptr;
        return true;
    }

    std::unordered_set<chess::Position, chess::PositionHash> Echiquier::getFilteredMovement() {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getCase(*lastSelected).getPieceInfo()->getListeDeplacements(*lastSelected, *this);
        std::erase_if(positions, [&](const chess::Position& pos) {
            std::unique_ptr<chess::Piece> piece  = getCase(pos).getPiece();
            moveTo(*lastSelected, pos);
            if (isCheck(joueur_)) {
                moveTo(pos, *lastSelected);
                getCase(pos).setPiece(std::move(piece));
                return true; 
            }
            moveTo(pos, *lastSelected);
            getCase(pos).setPiece(std::move(piece));
            return false;
            });
        return positions;

        
    }

    void Echiquier::moveTo(const chess::Position& start, const chess::Position& destination, bool display ) {
            getCase(destination).setPiece(getCase(start).getPiece(), display);
            getCase(start).setPiece(nullptr, display);
    }
    void Echiquier::moveToValid(const chess::Position& start, const chess::Position& destination) {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getFilteredMovement();
        auto it = positions.find(destination);
        if (it != positions.end()) {
        getCase(destination).setPiece(getCase(start).getPiece(), true);
        getCase(start).setPiece(nullptr, true);
        joueur_ = getInverseColor(joueur_);

        }
    }

  
    bool Echiquier::isValidClick(const chess::Position& position) {
        if (lastSelected == nullptr) {
            if (getCase(position).getPieceInfo() != nullptr && getCase(position).getPieceInfo()->getCouleur() == joueur_) {
                if (getCase(position).getPieceInfo() != nullptr) {
                    lastSelected = std::make_unique<chess::Position>(position);
                    getCase(*lastSelected).setSelect(true);
                    selectPostions(true);
                }
            }
            return false;
        }
        else if ( (lastSelected != nullptr) && (*lastSelected) == position) {
            selectPostions(false);
            getCase(*lastSelected).setSelect(false);
            lastSelected = nullptr;
            return false; 
        }
        return true;
    }
    void Echiquier::handleButtonClick(const chess::Position& position) {
        //fonction principale du jeu. Déclencher lors d'un click sur une case
        if (isValidClick(position)) {
            selectPostions(false);
            moveToValid(*lastSelected, position);
            getCase(*lastSelected).setSelect(false);
            checkMate_ = isCheckMate();
            lastSelected = nullptr;
            
        }
    }
    void Echiquier::handleStartButton() {

    }
    bool Echiquier::isColor(chess::Couleur color, const chess::Position& position) {
        return getCase(position).getPieceInfo()->getCouleur() == color;
    }
    
    void Echiquier::selectPostions( bool select) {
        std::unordered_set<chess::Position,chess::PositionHash> positions = getFilteredMovement();
        for (auto position : positions) {
            getCase(position).setSelect(select);
        }
    }
    std::unordered_set<chess::Position, chess::PositionHash>  Echiquier::getAllMovements(const chess::Couleur& color) {
        std::unordered_set<chess::Position, chess::PositionHash> positions;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess::Position pos(i, j);
                if ((getCase(pos).getPieceInfo() != nullptr) &&getCase(pos).getPieceInfo()->getCouleur() == color) {
                    std::unordered_set<chess::Position, chess::PositionHash> tempPositions = getCase(pos).getPieceInfo()->getListeDeplacements(pos, *this);
                    std::copy(tempPositions.begin(), tempPositions.end(), std::inserter(positions, positions.end()));
                    
                }
               
            }
        }
        return positions;
    }

}

