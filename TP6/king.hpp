#pragma once
#include "Piece.hpp"
#include <iostream>

namespace chess {
    class King : public Piece {
    public:
        King(Color color);
        ~King();

        std::unordered_set<Position, PositionHash> getMovementsList(const Position& start,  ui::Board&) const override;
    private:
        static int instanceCount_;


    };
    
    
}
