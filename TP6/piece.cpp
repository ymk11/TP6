#include "Piece.hpp"
#include "board.hpp"



namespace chess {

	Piece::Piece(TypePiece type, Color couleur, std::string black, std::string white) : type_(type),
		color_(couleur) {
		if (couleur == Color::Black) {
			image_ = QString::fromStdString(black);
		}
		else {
			image_ = QString::fromStdString(white);
		}
	}


	const TypePiece& Piece::getTypePiece()const { return type_; }
	const Color& Piece::getColor() const { return color_; }
	const QString& Piece::getImage() const { return image_; }
}