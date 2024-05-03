#pragma once
#include <QPushButton>
#include "piece.hpp"
#include "knight.hpp"
#include "king.hpp"
#include "tower.hpp"
#include "position.hpp"
#include "board.hpp"

#include <memory>


class RAII {
public:
    RAII(ui::Board& board, const chess::Position& start, const chess::Position& destination);

    ~RAII();

private:
    ui::Board& echiquier_;
    chess::Position start_;
    chess::Position destination_;
};