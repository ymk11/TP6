#pragma once
#include <QPushButton>
#include "piece.hpp"
#include "cavalier.hpp"
#include "roi.hpp"
#include "tour.hpp"
#include "position.hpp"
#include <memory>
using namespace chess

class RAII {
public:
	RAII(Piece& piece, char new_position);
	~RAII();

}