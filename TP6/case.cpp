#include "case.hpp"
#include <Qsize>


namespace chess {

	Case::Case(const Couleur& color, const Position& position, std::unique_ptr<Piece> piece, QWidget* parent) :
		QPushButton(), position_(position), piece_(std::move(piece)) {
		connect(this, &QPushButton::clicked, this, &Case::onClicked);
		if (color == Couleur::White) {
			style_ = ("QPushButton {"
				"    background-color: darkgreen;"
				"    border: none;"
				"    color: white;"
				"}");
		}
		else {
			style_ = ("QPushButton {"
				"    background-color: white;"
				"    border: none;"
				"    color: white;"
				"}");
		}
		QPushButton::setStyleSheet(style_);
		updateAppearance();
	}
	Case::Case(const Couleur& color, const Position& position, QWidget* parent) :
		Case(color, position, nullptr, parent) {}

	void Case::setPiece(std::unique_ptr<Piece> newPiece, bool update) {
		piece_ = std::move(newPiece);
		if (update) { updateAppearance(); }
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
	
	void Case::setSelect(bool select){
		if (select) {
			QPushButton::setStyleSheet("QPushButton {"
				"    background-color: cyan;"
				"    border: none;"
				"    color: white;"
				"}");
		}
		else{
			QPushButton::setStyleSheet(style_);
		}

		
	}
	void Case::turnRed() {
		QPushButton::setStyleSheet("QPushButton {"
			"    background-color: red;"
			"    border: none;"
			"    color: white;"
			"}");
	}
}