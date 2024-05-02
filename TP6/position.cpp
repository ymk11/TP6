#include "Position.hpp"


namespace chess {

	
	Position::Position() : x_(0), y_(0) {}

	Position::Position(int x, int y) : x_(x), y_(y) {}
	
	Position::Position(const Position& other) : x_(other.x_), y_(other.y_) {}

	int Position::getX() const { return x_; }

	int Position::getY() const { return y_; }

	void Position::setX(int x) { x_ = x; }

	void Position::setY(int y) { y_ = y; }

	bool Position::estValide() const { return (x_ >= 0) && (x_ <= 8) && (y_ >= 0) && (y_ <= 8); }

	bool Position::operator==(const Position& other) const { return (x_ == other.x_) && (y_ == other.y_); }

	Position& Position::operator=(const Position& other) {
		if (this != &other) {
			x_ = other.x_;
			y_ = other.y_;
		}
		return *this;
	}

	size_t PositionHash::operator()(const Position& position) const {
		return std::hash<int>()(position.getX()) ^ (std::hash<int>()(position.getY()) << 1);
	}
}


	
