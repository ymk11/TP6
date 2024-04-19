#include "echiquier.hpp"



namespace ui {
    Echiquier::Echiquier(QWidget* parent) : QMainWindow(parent) {

        initializeBoard();
    }

    void Echiquier::initializeBoard() { //initialiser l'UI

        //for (int i = 0; i < 8; i++) {
        //    for (int j = 0; j < 8; j++) {
        //        plateau_[i][j] = nullptr; //  vide
        //        connect(&plateau_[i][j], &Case::caseClicked, this, &Echiquier::handleButtonClick);
        //    }
        //}



    }
     chess::Case& Echiquier::getCase(const chess::Position& position) {
        return plateau_[position.getY()][position.getX()];
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
