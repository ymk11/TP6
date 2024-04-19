#pragma once
#include "couleur.hpp"
#include "typepiece.hpp"
#include "position.hpp"
#include <vector>
#include <string>
#include <QString>

class Echiquier;

class Piece {
public:
    

    Piece(TypePiece type, Couleur couleur, std::string image);
    virtual ~Piece() = default;

    virtual const TypePiece& getTypePiece() const;
    virtual const Couleur& getCouleur() const ;
    virtual  const QString& getImage() const;
    virtual std::vector<Position> getListeDeplacements(const Position& depart, const Echiquier&) const = 0;

private:
    TypePiece type_;
    Couleur couleur_;
    QString image_;
};


