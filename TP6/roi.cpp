#include "roi.hpp"



Roi::Roi(Couleur couleur): Piece(TypePiece::Roi,couleur, "♔") {}

bool Roi::estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier) const {

    if (abs(depart.getX() - arrivee.getX()) <= 1 && abs(depart.getX() - arrivee.getY()) <= 1) {
        return true;
    }


    return false;
}

std::vector<Position> Roi::getListeDeplacementsValide(const Position& départ, const Echiquier& echiquier) const {
    std::vector<Position> vect;
    return vect;
}
