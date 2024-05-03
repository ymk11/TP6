#pragma once
#include "Piece.hpp"
#include <iostream>

namespace chess {
	class Tower : public Piece {
	public:
		Tower(Color color);

		std::unordered_set<Position, PositionHash> getMovementsList(const Position& start,  ui::Board&) const override;

	};
}


