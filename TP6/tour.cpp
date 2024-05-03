#include "Tour.hpp"
#include "echiquier.hpp"
namespace chess {

    Tower::Tower(Couleur couleur) : Piece(TypePiece::Tower, couleur,
        "..\\assets\\rd.png", "..\\assets\\rl.png") {}


    std::unordered_set<Position, PositionHash> Tower::getMovementsList(const Position& start,  ui::Board& echiquier) const {
        std::unordered_set<Position, PositionHash> positions;
        std::vector<Position> displacementList{ Position(1,0), Position(-1,0) , Position(0,1), Position(0,-1) };
        for (auto disp : displacementList) {
            int j = 1;
            bool flag = true;
            while ((j <= 7) && flag) {
                Position futurPosition = Position(start.getX() + j * disp.getX(),
                    start.getY() + j * disp.getY());
                if (!futurPosition.estValide()) {
                    flag = false;
                   
                }
                else if (!echiquier.isEmptyCase(futurPosition)) {
                    if (!echiquier.isColor(Piece::getColor(), futurPosition)) {
                        positions.insert(futurPosition);
                    }
                    flag = false;
                }
                else {
                    positions.insert(futurPosition);
                }
                j++;
            }
        }
        return positions;
    }
}
