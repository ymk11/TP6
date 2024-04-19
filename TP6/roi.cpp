#include "roi.hpp"



Roi::Roi(Couleur couleur): Piece(TypePiece::Roi,couleur, "♔") {}

//bool Roi::estDeplacementValide(const Position& depart, const Position& arrivee) const {
//
//    if (abs(depart.getX() - arrivee.getX()) <= 1 && abs(depart.getX() - arrivee.getY()) <= 1) {
//        return true;
//    }
//
//
//    return false;
//}

std::vector<Position> Roi::getListeDeplacements(const Position& depart, const Echiquier&) const {
    std::vector<Position> vect;
    return vect;
}
