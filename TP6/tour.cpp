#include "Tour.hpp"


Tour::Tour(Couleur couleur) : Piece(TypePiece::Tour, couleur,"♖") {}

//bool Tour::estDeplacementValide(const Position& depart, const Position& arrivee)  const {
//
//    if (depart.getX() != arrivee.getX() && depart.getY() != arrivee.getY()) {
//        return false;
//    }
//
//
//    int directionX = (arrivee.getX() - depart.getX()) / abs(arrivee.getX() - depart.getX());
//    int directionY = (arrivee.getY() - depart.getY()) / abs(arrivee.getY() - depart.getY());
//    for (int i = 1; i < abs(arrivee.getX() - depart.getX()) || i < abs(arrivee.getY() - depart.getY()); ++i) {
//        Position caseIntermediaire(depart.getX() + i * directionX, depart.getY() + i * directionY);
//        //if (echiquier.getPiece(caseIntermediaire) != nullptr) {
//        //    return false;
//       // }
//    }
//
//   // Piece* pieceArrivee = echiquier.getPiece(arrivee);
//    //return pieceArrivee == nullptr || pieceArrivee->getCouleur() != this->getCouleur();
//    return true;
//}

std::vector<Position> Tour::getListeDeplacements(const Position& départ, const Echiquier&) const {
    std::vector<Position> vect;
    return vect;
}
