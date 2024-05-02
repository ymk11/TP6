#pragma once
#include "Piece.hpp"
#include <iostream>



namespace chess {
	class Cavalier : public Piece {
	public:
		Cavalier(Couleur couleur);
		std::unordered_set<Position, PositionHash> getListeDeplacements(const Position& depart, ui::Echiquier&) const override;

	};
}


