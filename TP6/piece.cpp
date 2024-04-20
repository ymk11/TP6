#include "Piece.hpp"
#include "echiquier.hpp"



namespace chess {

	Piece::Piece(TypePiece type, Couleur couleur, std::string black, std::string white) : type_(type),
		couleur_(couleur) {
		if (couleur == Couleur::Noir) {
			image_ = QString::fromStdString(black);
		}
		else {
			image_ = QString::fromStdString(white);
		}
	}


	const TypePiece& Piece::getTypePiece()const { return type_; }
	const Couleur& Piece::getCouleur() const { return couleur_; }
	const QString& Piece::getImage() const { return image_; }
}