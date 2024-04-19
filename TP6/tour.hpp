#pragma once
#include "Piece.hpp" 
#include <iostream>

namespace chess {
	class Tour : public Piece {
	public:
		Tour(Couleur couleur);

		std::vector<Position> getListeDeplacements(const Position& depart, const ui::Echiquier&) const override;

	};
}


