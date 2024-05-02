#pragma once
#include "Piece.hpp"
#include <iostream>

namespace chess {
    class Roi : public Piece {
    public:
        Roi(Couleur couleur);
        ~Roi();

        std::unordered_set<Position, PositionHash> getListeDeplacements(const Position& depart,  ui::Echiquier&) const override;
    private:
        static int instanceCount_;


    };
    
    
}
