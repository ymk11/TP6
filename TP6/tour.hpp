#pragma once
#include "Piece.hpp" 
#include <iostream>


class Tour : public Piece {
public:
	Tour(Couleur couleur);

	bool estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier)  const override;
	std::vector<Position> getListeDeplacementsValide(const Position& départ, const Echiquier& echiquier) const override;

};


