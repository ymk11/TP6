#include "Piece.hpp"
#include "case.hpp"




Piece::Piece(TypePiece type, Couleur couleur, std::string image) : type_(type), 
			couleur_(couleur), image_(QString::fromStdString(image)) {}


const TypePiece& Piece::getTypePiece()const {return type_;}
const Couleur& Piece::getCouleur() const {return couleur_;}
const QString& Piece::getImage() const {return image_;}