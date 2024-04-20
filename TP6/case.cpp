#include "case.hpp"
#include <Qsize>


namespace chess {

	Case::Case(const Couleur& couleur, const Position& position, std::unique_ptr<Piece> piece, QWidget* parent) :
		QPushButton(), position_(position), piece_(std::move(piece)) {
		connect(this, &QPushButton::clicked, this, &Case::onClicked);
		if (couleur == Couleur::Blanc) {
			QPushButton::setStyleSheet("QPushButton {"
				"    background-color: brown;"  
				"    border: none;"            
				"    color: white;"             
				"}");
		}
		else {
			QPushButton::setStyleSheet("QPushButton {"
				"    background-color: white;"
				"    border: none;"
				"    color: white;"
				"}");
		}
		updateAppearance();
	}
	Case::Case(const Couleur& couleur, const Position& position,  QWidget* parent) :
		QPushButton(), position_(position) {
		connect(this, &QPushButton::clicked, this, &Case::onClicked);
		if (couleur == Couleur::Blanc) {
			QPushButton::setStyleSheet("QPushButton {"
				"    background-color: brown;"
				"    border: none;"
				"    color: white;"
				"}");
		}
		else {
			QPushButton::setStyleSheet("QPushButton {"
				"    background-color: white;"
				"    border: none;"
				"    color: white;"
				"}");
		}
		updateAppearance();
	}

	void Case::setPiece(std::unique_ptr<Piece> newPiece) {
		piece_ = std::move(newPiece);
		updateAppearance();
	}

	const std::unique_ptr<Piece>& Case::getPieceInfo()const { return piece_; }

	std::unique_ptr<Piece> Case::getPiece() { return std::move(piece_); }

	const Position& Case::getPosition() const { return position_; }

	void Case::onClicked() { emit caseClicked(position_); }

	void Case::updateAppearance() {
		if (piece_ == nullptr) {
			QPushButton::setIcon(QIcon());
		}
		else {
			QPushButton::setIcon(QIcon(piece_->getImage()));
			QPushButton::setIconSize(QSize(90, 90));
		}
	}
}