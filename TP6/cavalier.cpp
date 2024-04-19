#include "cavalier.hpp"


Cavalier::Cavalier(Couleur couleur) : Piece(TypePiece::Cavalier, couleur, "♞") {}

//bool Cavalier::estDeplacementValide(const Position& depart, const Position& arrivee) const  {
//    // vérifier si le déplacement correspond au mouvement du cavalier (deux cases dans une direction et une case dans l'autre)
//    int differencex = abs(arrivee.getX() - depart.getX());
//    int differencey = abs(arrivee.getY() - depart.getY());
//
//    if ((differencex == 2 && differencey == 1) || (differencex == 1 && differencey == 2)) {
//        return true;
//    }
//    else {
//        return false;
//    }
//    //Piece* piecearrivee = echiquier.getpiece(arrivee);
//    //return piecearrivee == nullptr || piecearrivee->getcouleur() != this->getcouleur();
//    return 0;
//}

std::vector<Position> Cavalier::getListeDeplacements(const Position& départ, const Echiquier&) const {
    std::vector<Position> vect;
    return vect;
}
