#pragma once
#include "Piece.hpp" 
#include <iostream>


class Tour : public Piece {
public:
	Tour(Couleur couleur);

	std::vector<Position> getListeDeplacements(const Position& depart) const override;

};


