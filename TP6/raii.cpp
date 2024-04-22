#include "RAII.hpp"


RAII::RAII(Echiquier& echiquier, const Position& start, const Position& destination)
    : echiquier_(echiquier), start_(start), destination_(destination) {

    echiquier_.moveTo(start_, destination_);
}

RAII::~RAII() {
    echiquier_.moveTo(destination_, start_);
}