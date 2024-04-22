#pragma once
#include <QPushButton>
#include "piece.hpp"
#include "cavalier.hpp"
#include "roi.hpp"
#include "tour.hpp"
#include "position.hpp"
#include "echiquier.hpp"

#include <memory>


class RAII {
public:
    RAII(Echiquier& echiquier, const Position& start, const Position& destination);

    ~RAII();

private:
    Echiquier& echiquier_;
    Position start_;
    Position destination_;
};