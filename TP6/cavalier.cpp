//#include "Cavalier.hpp"
//#include <iostream>
//
//Cavalier::Cavalier(Couleur couleur) : Piece(TypePiece::Cavalier, couleur) {}
//
//bool Cavalier::estDeplacementValide(const Echiquier& echiquier, const Position& depart, const Position& arrivee) const {
//    // Vérifier si le déplacement correspond au mouvement du cavalier (deux cases dans une direction et une case dans l'autre)
//    int differenceX = abs(arrivee.getX() - depart.getX());
//    int differenceY = abs(arrivee.getY() - depart.getY());
//
//    if ((differenceX == 2 && differenceY == 1) || (differenceX == 1 && differenceY == 2)) {
//        return true;
//    }
//    else {
//        return false;
//    }
//    Piece* pieceArrivee = echiquier.getPiece(arrivee);
//    return pieceArrivee == nullptr || pieceArrivee->getCouleur() != this->getCouleur();
//}
