#include "Piece.hpp"


Piece::Piece(TypePiece type, Couleur couleur, std::string representation) : type_(type), 
			couleur_(couleur), representation_(QString::fromStdString(representation)) {}


const TypePiece& Piece::getTypePiece()const {return type_;}
const Couleur& Piece::getCouleur() const {return couleur_;}
const QString& Piece::getRepresentation() const {return representation_;}