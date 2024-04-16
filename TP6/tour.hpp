#ifndef TOUR_H
#define TOUR_H

#include "Piece.hpp" 
#include <iostream>
#pragma once

class Tour : public Piece {
public:
	Tour(TypePiece type, Couleur couleur, std::string representation);

	bool estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier)  const override;
	std::vector<Position> getListeDeplacementsValide(const Position& départ, const Echiquier& echiquier) const override;

};

#endif // TOUR_H
