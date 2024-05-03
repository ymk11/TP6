#include "roi.hpp"
#include "echiquier.hpp"
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

   

    std::unordered_set<Position, PositionHash> Roi::getListeDeplacements(const Position& start,  ui::Echiquier& echiquier) const {
        std::unordered_set<Position, PositionHash> positions;
        std::vector<Position> displacementList = { Position(1, 0),
            Position(-1, 0),
            Position(0, 1),
            Position(0, -1),
            Position(1, 1),
            Position(1, -1),
            Position(-1, -1),
            Position(-1, 1), };
        
        for (auto disp : displacementList) {
            Position positionFutur(start.getX() + disp.getX(), start.getY() + disp.getY());
            if (positionFutur.estValide() &&
                (echiquier.isEmptyCase(positionFutur) || !echiquier.isColor(Piece::getCouleur(), positionFutur))) {
                positions.insert(positionFutur);
            }
        }
        return positions;
    }
    Roi::~Roi() {
        instanceCount_--;
    }
}