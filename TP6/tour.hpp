#pragma once
#include "Piece.hpp"
#include <iostream>

namespace chess {
	class Tour : public Piece {
	public:
		Tour(Couleur couleur);

		std::unordered_set<Position, PositionHash> getListeDeplacements(const Position& depart,  ui::Echiquier&) const override;

	};
}


