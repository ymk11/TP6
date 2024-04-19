#pragma once
#include "Piece.hpp"
#include <iostream>

namespace chess {
    class Roi : public Piece {
    public:
        Roi(Couleur couleur);
        ~Roi();

        std::vector<Position> getListeDeplacements(const Position& depart, const ui::Echiquier&) const override;
    private:
        static int instanceCount_;


    };
    
    
}
