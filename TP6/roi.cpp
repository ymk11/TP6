#include "roi.hpp"
#include "echiquier.hpp"
#include "kingException.hpp"

namespace chess {

    int King::instanceCount_ = 0;

    King::King(Couleur couleur) : Piece(TypePiece::King, couleur,
        "..\\assets\\kd.png", "..\\assets\\kl.png") {
        instanceCount_++;
        if (instanceCount_ > 2) {
            throw KingException("Nombre de roir excédé : (2)");
        }
    }

   

    std::unordered_set<Position, PositionHash> King::getMovementsList(const Position& start,  ui::Board& echiquier) const {
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
                (echiquier.isEmptyCase(positionFutur) || !echiquier.isColor(Piece::getColor(), positionFutur))) {
                positions.insert(positionFutur);
            }
        }
        return positions;
    }
    King::~King() {
        instanceCount_--;
    }
}