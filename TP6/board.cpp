#include "board.hpp"
#include "king.hpp"
#include "tower.hpp"
#include "knight.hpp"
#include "QLabel"
#include <QRadioButton>
#include <QMessageBox>



namespace ui {
    Board::Board(QWidget* parent) : QMainWindow(parent) {
        centralWidget_ = new QWidget();
        mainWindow_ = new QHBoxLayout(this);
        mainWindow_->setSpacing(55);
        mainWindow_->setContentsMargins(QMargins(15,15,50,15));
        setCentralWidget(centralWidget_);
        centralWidget_->setLayout(mainWindow_);
        initializeBoard();
        initializeMenu();
    }

    void Board::initializeBoard() { 
        using namespace chess;
        plateau_.resize(8);
        for (int i = 0; i < 8; ++i) {
            plateau_[i].resize(8);
        }

        setWindowTitle(" Chess Game");
        chessBoard_ = new QVBoxLayout() ;
        chessBoard_->setSpacing(0);
        mainWindow_->addLayout(chessBoard_);
        for (int i = 0; i < 8; i++) {
            QHBoxLayout* hBoxLayout = new QHBoxLayout();
            hBoxLayout->setSpacing(0);

            for (int j = 0; j < 8; j++) {
                Color couleur = Color::White;
                if ((j+i) % 2 == 0) {
                    couleur = Color::Black;
                }
                plateau_[i][j] = std::make_unique<Case>(couleur,Position(i,j));
                plateau_[i][j]->setMinimumSize(140, 140);

                
                connect(plateau_[i][j].get(), &Case::caseClicked, this, &Board::handleButtonClick);

                
                hBoxLayout->addWidget(plateau_[i][j].get());
            }
            chessBoard_->addLayout(hBoxLayout);
        }
    }

    void Board::initializeMenu() {
        QVBoxLayout* menuBox = new QVBoxLayout();
        menuBox->setAlignment(Qt::AlignTop);

        QPushButton* startButton = new QPushButton("Start Game");
        QPushButton* endButton = new QPushButton("End Game");

        connect(startButton, &QPushButton::clicked, this, &Board::handleStartButton);
        connect(endButton, &QPushButton::clicked, [this]() {
            if (gameInProgress_) {
                
                if ((lastSelected_ != nullptr)) {
                    selectPostions(false);
                    getCase(*lastSelected_).setSelect(false);
                }
                else if (turnedRed_) { getCase(redPosition_).setSelect(false); }
                ready_ = false;
                checkMate_ = true;
                QMessageBox::information(nullptr, "Information", "Game ended!");
            }
            });
        menuBox->addWidget(startButton);


        startButton->setMinimumSize(200, 30);
        endButton->setMinimumSize(200, 30);

        mainWindow_->addLayout(menuBox);

        QVBoxLayout* labelBox = new QVBoxLayout();
        QLabel* label = new QLabel("Select starting board");
        labelBox->setAlignment(Qt::AlignCenter);
        labelBox->addWidget(label);


        menuBox->addLayout(labelBox);

 
        QVBoxLayout* optionsLayout = new QVBoxLayout();
        QStringList options = { "Board 1", "Board 2", "Board 3", "Board 4" };

        for (const QString& option : options) {
            QRadioButton* radioButton = new QRadioButton(option);
            optionsLayout->addWidget(radioButton);
            connect(radioButton, &QRadioButton::toggled, [option, this]() {
                if (checkMate_) {
                    int choice = 0;
                    if (option == "Board 2") {
                        choice = 1;

                    }
                    else if (option == "Board 3") {
                        choice = 2;

                    }
                    else if (option == "Board 4") {
                        choice = 3;

                    }
                    setBoard(choice);
                }
                });
        }


        labelBox->addLayout(optionsLayout);
        menuBox->addWidget(endButton);

        
    }

    chess::Case& Board::getCase(const chess::Position& position) {
        return *plateau_[position.getX()][position.getY()];
    }

    void Board::setCase(const chess::Position& position, std::unique_ptr<chess::Piece> piece) {
        getCase(position).setPiece(std::move(piece));
    }

    bool Board::isEmptyCase(const chess::Position& position) {
        return getCase(position).getPieceInfo() == nullptr;

    }
    chess::Color Board::getInverseColor(const chess::Color& color) {
        return (color == chess::Color::White) ? chess::Color::Black : chess::Color::White;
    }
    chess::Position Board::kingPosition(const chess::Color& color) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess::Position pos(i, j);
                if ((getCase(pos).getPieceInfo() != nullptr) && (getCase(pos).getPieceInfo()->getColor() == color)
                    && (getCase(pos).getPieceInfo()->getTypePiece() == chess::TypePiece::King)) {
                    return pos;
                }

            }
        }
        return {};
    }
    
    bool Board::isCheck(const chess::Color& color) {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getAllMovements(getInverseColor(color));
        bool val  = positions.find(kingPosition(color)) != positions.end();
        return val;
    }
    bool Board::isCheckMate() {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getAllMovements(joueur_);
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess::Position postion(i, j);
                if ((getCase(postion).getPieceInfo() != nullptr) && (getCase(postion).getPieceInfo()->getColor() == joueur_)) {
                    lastSelected_ = std::make_unique<chess::Position>(postion);
                    if (!getFilteredMovement().empty()) {
                        lastSelected_ = nullptr;
                        return false;
                    }
                }
            }
        }
        lastSelected_ = nullptr;
        return true;
    }

    std::unordered_set<chess::Position, chess::PositionHash> Board::getFilteredMovement() {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getCase(*lastSelected_).getPieceInfo()->getMovementsList(*lastSelected_, *this);
        std::erase_if(positions, [&](const chess::Position& pos) {
            std::unique_ptr<chess::Piece> piece  = getCase(pos).getPiece();
            moveTo(*lastSelected_, pos);
            if (isCheck(joueur_)) {
                moveTo(pos, *lastSelected_);
                getCase(pos).setPiece(std::move(piece));
                return true; 
            }
            moveTo(pos, *lastSelected_);
            getCase(pos).setPiece(std::move(piece));
            return false;
            });
        return positions;

        
    }

    void Board::moveTo(const chess::Position& start, const chess::Position& destination, bool display ) {
            getCase(destination).setPiece(getCase(start).getPiece(), display);
            getCase(start).setPiece(nullptr, display);
    }
    void Board::moveToValid(const chess::Position& start, const chess::Position& destination) {
        std::unordered_set<chess::Position, chess::PositionHash> positions = getFilteredMovement();
        auto it = positions.find(destination);
        if (it != positions.end()) {
            getCase(destination).setPiece(getCase(start).getPiece(), true);
            getCase(start).setPiece(nullptr, true);
            joueur_ = getInverseColor(joueur_);
            getCase(*lastSelected_).setSelect(false);
            turnedRed_ = false;
        }
        else {
            turnedRed_ = true;
            redPosition_ = start;
            getCase(start).turnRed();
        }
    }

  
    bool Board::isValidClick(const chess::Position& position) {
        if (checkMate_) {return false; }
        else if (lastSelected_ == nullptr) {
            if (turnedRed_) { getCase(redPosition_).setSelect(false); }
            if (getCase(position).getPieceInfo() != nullptr && getCase(position).getPieceInfo()->getColor() == joueur_) {
                if (getCase(position).getPieceInfo() != nullptr) {
                    lastSelected_ = std::make_unique<chess::Position>(position);
                    getCase(*lastSelected_).setSelect(true);
                    selectPostions(true);
                    gameInProgress_ = true;
                }
            }
            return false;
        }

        else if ( (lastSelected_ != nullptr) && (*lastSelected_) == position) {
            selectPostions(false);
            getCase(*lastSelected_).setSelect(false);
            lastSelected_ = nullptr;
            return false; 
        }

        else if ((getCase(position).getPieceInfo() != nullptr) &&
            (getCase(position).getPieceInfo()->getColor() == getCase(*lastSelected_).getPieceInfo()->getColor())) {
            getCase(*lastSelected_).setSelect(false);
            selectPostions(false);
            lastSelected_ = std::make_unique<chess::Position>(position);
            getCase(*lastSelected_).setSelect(true);
            selectPostions(true);
            return false;
        }

        return true;
    }
    void Board::handleButtonClick(const chess::Position& position) {
        if (isValidClick(position) ) {
            selectPostions(false);
            moveToValid(*lastSelected_, position);
            checkMate_ = isCheckMate();
            lastSelected_ = nullptr;
            if (checkMate_) {
                endGame();
            }
            
            
        }
    }
    void Board::handleStartButton() {
        if (ready_) {
            checkMate_ = false;
            ready_ = false;
            QMessageBox::information(nullptr, "Information", "The game has started!");
        }
    }
    bool Board::isColor(chess::Color color, const chess::Position& position) {
        return getCase(position).getPieceInfo()->getColor() == color;
    }
    
    void Board::selectPostions( bool select) {
        std::unordered_set<chess::Position,chess::PositionHash> positions = getFilteredMovement();
        for (auto position : positions) {
            getCase(position).setSelect(select);
        }
    }
    std::unordered_set<chess::Position, chess::PositionHash>  Board::getAllMovements(const chess::Color& color) {
        std::unordered_set<chess::Position, chess::PositionHash> positions;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chess::Position pos(i, j);
                if ((getCase(pos).getPieceInfo() != nullptr) &&getCase(pos).getPieceInfo()->getColor() == color) {
                    std::unordered_set<chess::Position, chess::PositionHash> tempPositions = getCase(pos).getPieceInfo()->getMovementsList(pos, *this);
                    std::copy(tempPositions.begin(), tempPositions.end(), std::inserter(positions, positions.end()));
                    
                }
               
            }
        }
        return positions;
    }
    void Board::emptyBoard() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                plateau_[i][j]->setPiece(nullptr, true);
            }
        }

    }
    void Board::setBoard(int modifier) {
        using namespace chess;
        using std::make_unique;
        emptyBoard();
        ready_ = true;
        if (modifier == 0) {
            plateau_[0][4]->setPiece(make_unique<King>(King(Color::Black)), true);
            plateau_[1][5]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[1][2]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[0][0]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);
            plateau_[0][7]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);

            plateau_[7][4]->setPiece(make_unique<King>(King(Color::White)), true);
            plateau_[6][5]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[6][2]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[7][0]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
            plateau_[7][7]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
        }
        else if (modifier == 1) {
            plateau_[0][1]->setPiece(make_unique<King>(King(Color::Black)), true);
            plateau_[2][3]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[1][2]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[5][0]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);
            plateau_[0][7]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);

            plateau_[5][0]->setPiece(make_unique<King>(King(Color::White)), true);
            plateau_[7][3]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[6][2]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[4][4]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
            plateau_[7][4]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
        }
        else if (modifier == 2) {
            plateau_[0][5]->setPiece(make_unique<King>(King(Color::Black)), true);
            plateau_[3][5]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[3][2]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[1][0]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);
            plateau_[1][7]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);

            plateau_[7][5]->setPiece(make_unique<King>(King(Color::White)), true);
            plateau_[4][5]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[4][2]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[7][1]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
            plateau_[6][6]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
        }
        else if (modifier == 3) {
            plateau_[0][5]->setPiece(make_unique<King>(King(Color::Black)), true);
            plateau_[3][5]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[3][2]->setPiece(make_unique<Knight>(Knight(Color::Black)), true);
            plateau_[2][0]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);
            plateau_[2][7]->setPiece(make_unique<Tower>(Tower(Color::Black)), true);

            plateau_[7][4]->setPiece(make_unique<King>(King(Color::White)), true);
            plateau_[4][5]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[4][2]->setPiece(make_unique<Knight>(Knight(Color::White)), true);
            plateau_[6][4]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
            plateau_[6][7]->setPiece(make_unique<Tower>(Tower(Color::White)), true);
        }
    }

    void Board::endGame() {
        ready_ = false;
        QString winner = (joueur_ == chess::Color::White) ? "Black" : "White";
        QMessageBox::information(nullptr, "Information", (winner + " won!"));

    }
}

