#pragma once
#include "Piece.hpp"
#include <iostream>

class Cavalier : public Piece {
public:
	Cavalier(Couleur couleur);
	bool estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier) const override;
	std::vector<Position> getListeDeplacementsValide(const Position& d�part, const Echiquier& echiquier) const override;

};


