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
        plateau_[3][4]->setPiece(std::make_unique<Roi>(Roi(Couleur::Blanc)));
        plateau_[4][4]->setPiece(std::make_unique<Cavalier>(Cavalier(Couleur::Blanc)));
        plateau_[3][3]->setPiece(std::make_unique<Tour>(Tour(Couleur::Noir)));
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



    bool Echiquier::estEchec() const {
        // to do ...
        return 0;
    }
    void Echiquier::moveTo(const chess::Position& start, const chess::Position& destination) {
        getCase(destination).setPiece(getCase(start).getPiece());
        getCase(start).setPiece(nullptr);
    }

    //bool echiquier::estdanslimitesechiquier(const position& position) const {
    //    return position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8;
    //} 
    // La liste de position valide s'assurera que rien n'est hors position
    bool Echiquier::isValidClick(const chess::Position& position) {
        if (lastSelected == nullptr) {
            if (getCase(position).getPieceInfo() != nullptr) {
                lastSelected = std::make_unique<chess::Position>(position);
                getCase(*lastSelected).setSelect(true);
                selectPostions(true);
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
            moveTo(*lastSelected, position);
            getCase(*lastSelected).setSelect(false);
            lastSelected = nullptr;
            
        }
    }
    void Echiquier::handleStartButton() {

    }
    bool Echiquier::isColor(chess::Couleur color, const chess::Position& position) {
        return getCase(position).getPieceInfo()->getCouleur() == color;
    }
    
    void Echiquier::selectPostions( bool select) {
        std::unordered_set<chess::Position,chess::PositionHash> positions = getCase(*lastSelected).getPieceInfo()->getListeDeplacements(*lastSelected, *this);
        for (auto position : positions) {
            getCase(position).setSelect(select);
        }
    }

}

