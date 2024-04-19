#include "case.hpp"




Case::Case(const Position& position, std::unique_ptr<Piece> piece, QWidget* parent) :
			QPushButton(), position_(position), piece_(std::move(piece)) {
	connect(this, &QPushButton::clicked, this, &Case::onClicked);
	updateAppearance();
}
void Case::setPiece(std::unique_ptr<Piece> newPiece) {
	
	piece_ = std::move(newPiece);
	updateAppearance();
	
}

const std::unique_ptr<Piece>& Case::getPieceInfo()const {return piece_;}

std::unique_ptr<Piece> Case::getPiece() {return std::move(piece_);}

const Position& Case::getPosition() const {return position_;}

void Case::onClicked() {emit caseClicked(position_);}

void Case::updateAppearance() {
	if (piece_ == nullptr) {
		QPushButton::setIcon(QIcon());
	}
	else {
		QPushButton::setIcon(QIcon(piece_->getImage()));
	}
}