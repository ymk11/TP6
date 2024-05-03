#include "RAII.hpp"


RAII::RAII(ui::Board& echiquier, const chess::Position& start, const chess::Position& destination)
    : echiquier_(echiquier), start_(start), destination_(destination) {
    echiquier_.moveTo(start_, destination_);
}

RAII::~RAII() {
    echiquier_.moveTo(destination_, start_);
}