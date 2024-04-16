#ifndef CAVALIER_H
#define CAVALIER_H

#include "Piece.hpp"
#include <iostream>
#pragma once

class Cavalier : public Piece {
public:
	Cavalier(TypePiece type, Couleur couleur, std::string representation);
	bool estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier) const override;
	std::vector<Position> getListeDeplacementsValide(const Position& départ, const Echiquier& echiquier) const override;

};

#endif // CAVALIER_H
