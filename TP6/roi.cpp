#include "roi.hpp"
#include "kingException.hpp"

namespace chess {

    int Roi::instanceCount_ = 0;

    Roi::Roi(Couleur couleur) : Piece(TypePiece::Roi, couleur,
        "..\\assets\\kd.png", "..\\assets\\kl.png") {
        instanceCount_++;
        if (instanceCount_ > 2) {
            throw KingException("Nombre de roir excédé : (2)");
        }
    }

    //bool Roi::estDeplacementValide(const Position& depart, const Position& arrivee) const {
    //
    //    if (abs(depart.getX() - arrivee.getX()) <= 1 && abs(depart.getX() - arrivee.getY()) <= 1) {
    //        return true;
    //    }
    //
    //
    //    return false;
    //}

    std::vector<Position> Roi::getListeDeplacements(const Position& depart, const ui::Echiquier&) const {
        std::vector<Position> vect;
        return vect;
    }
    Roi::~Roi() {
        instanceCount_--;
    }
}