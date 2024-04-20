#include "echiquier.hpp"
#include "Roi.hpp"
#include "tour.hpp"
#include "cavalier.hpp"



namespace ui {
    Echiquier::Echiquier(QWidget* parent) : QMainWindow(parent) {
        initializeBoard();
    }

    void Echiquier::initializeBoard() { //initialiser l'UI
        using namespace chess;
        QWidget* centralWidget = new QWidget;
        setCentralWidget(centralWidget);
        plateau_.resize(8);
        for (int i = 0; i < 8; ++i) {
            plateau_[i].resize(8);
        }

        setWindowTitle(" Chess Game");
        QVBoxLayout* mainWindow = new QVBoxLayout(this);
        QVBoxLayout* chessBoard = new QVBoxLayout() ;
        chessBoard->setSpacing(0);
        mainWindow->addLayout(chessBoard);
        for (int i = 0; i < 8; i++) {
            QHBoxLayout* hBoxLayout = new QHBoxLayout;
            hBoxLayout->setSpacing(0);

            for (int j = 0; j < 8; j++) {
                Couleur couleur = Couleur::Blanc;
                if ((j+i) % 2 == 0) {
                    couleur = Couleur::Noir;
                }
                plateau_[i][j] = std::make_unique<Case>(couleur,Position(3,4));
                plateau_[i][j]->setMinimumSize(140, 140);

                
                connect(plateau_[i][j].get(), &Case::caseClicked, this, &Echiquier::handleButtonClick);

                
                hBoxLayout->addWidget(plateau_[i][j].get());
            }
            chessBoard->addLayout(hBoxLayout);
        }
        
        centralWidget->setLayout(mainWindow); 
    }

    chess::Case& Echiquier::getCase(const chess::Position& position) {
        return *plateau_[position.getY()][position.getX()];
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

    void Echiquier::handleButtonClick(const chess::Position& position) {
        //fonction principale du jeu. Déclencher lors d'un click sur une case
    }

}
