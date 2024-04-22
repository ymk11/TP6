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
    RAII(ui::Echiquier& echiquier, const chess::Position& start, const chess::Position& destination);

    ~RAII();

private:
    ui::Echiquier& echiquier_;
    chess::Position start_;
    chess::Position destination_;
};