#pragma once
#include "Piece.hpp"
#include <iostream>

class Cavalier : public Piece {
public:
	Cavalier(Couleur couleur);
	std::vector<Position> getListeDeplacements(const Position& depart, const std::vector<std::vector<Case>>&) const override;

};


