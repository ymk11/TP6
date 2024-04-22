#pragma once
#include <QPushButton>
#include "piece.hpp"
#include "cavalier.hpp"
#include "roi.hpp"
#include "tour.hpp"
#include "position.hpp"
#include <memory>

class RAII {
public:
	RAII(Piece& piece, char new_position);
	~RAII();
private:
	Piece& piece_;
	char old_position_;
};
}