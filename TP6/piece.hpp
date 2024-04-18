#pragma once
#include <iostream>
#include "couleur.hpp"
#include "typepiece.hpp"
#include "position.hpp"
#include "echiquier.hpp"
#include <vector>
#include <string>
#include <QString>



class Piece {
public:
    

    Piece(TypePiece type, Couleur couleur, std::string representation);
    virtual ~Piece() = default;

    virtual const TypePiece& getTypePiece() const;
    virtual const Couleur& getCouleur() const ;
    virtual const QString& getRepresentation() const;

    virtual bool estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier) const = 0;
    virtual std::vector<Position> getListeDeplacementsValide(const Position& depart, const Echiquier& echiquier) const = 0;

private:
    TypePiece type_;
    Couleur couleur_;
    QString representation_;
};


