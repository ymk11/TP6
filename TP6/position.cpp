#include "Position.hpp"


Position::Position() : x_(0), y_(0) {}

Position::Position(int x, int y) : x_(x), y_(y) {}

int Position::getX() const { return x_; }

int Position::getY() const { return y_; }

void Position::setX(int x) {x_ = x; }

void Position::setY(int y) { y_ = y; }

bool Position::estValide() const {return (x_ >= 0) && (x_ <= 8) && (y_ >= 0) && (y_ <= 8);}
