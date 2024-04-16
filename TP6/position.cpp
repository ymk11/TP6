#include "Position.hpp"
#include <iostream>

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const { return x; }

int Position::getY() const { return y; }

void Position::setX(int x) { this->x = x; }

void Position::setY(int y) { this->y = y; }

bool Position::estValide() const {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
