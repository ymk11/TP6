#pragma once
#include "Piece.hpp"
#include <iostream>



namespace chess {
	class Knight : public Piece {
	public:
		Knight(Color color);
		std::unordered_set<Position, PositionHash> getMovementsList(const Position& start, ui::Board& board) const override;

	};
}


