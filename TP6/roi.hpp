#pragma once
#include "Piece.hpp"
#include <iostream>


class Roi : public Piece {
public:
    Roi( Couleur couleur);

    std::vector<Position> getListeDeplacements(const Position& depart, const Echiquier&) const override;
};
