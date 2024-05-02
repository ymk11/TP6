#include "Tour.hpp"

namespace chess {

    Tour::Tour(Couleur couleur) : Piece(TypePiece::Tour, couleur,
        "..\\assets\\rd.png", "..\\assets\\rl.png") {}

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

    std::unordered_set<Position, PositionHash> Tour::getListeDeplacements(const Position& départ,  ui::Echiquier&) const {
        std::unordered_set<Position, PositionHash> vect;
        return vect;
    }
}
