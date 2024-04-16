#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include "couleur.hpp"
#include "typepiece.hpp"
#include "position.hpp"
#include "echiquier.hpp"
#include <vector>
#include <string>

#pragma once

class Piece {
public:
    

    Piece(TypePiece type, Couleur couleur, std::string representation);
    virtual ~Piece();

    virtual const TypePiece& getTypePiece() ;
    virtual const Couleur& getCouleur() ;
    virtual const std::string& getRepresentation();

    virtual bool estDeplacementValide(const Position& depart, const Position& arrivee, Echiquier& echiquier) const = 0;
    virtual std::vector<Position> getListeDeplacementsValide(const Position& départ, const Echiquier& echiquier) const = 0;

private:
    TypePiece type;
    Couleur couleur;
    std::string representation;
};

#endif // PIECE_H
