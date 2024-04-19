#pragma once
#include "couleur.hpp"
#include "typepiece.hpp"
#include "position.hpp"
#include <vector>
#include <string>
#include <QString>



class Piece {
public:
    

    Piece(TypePiece type, Couleur couleur, std::string image);
    virtual ~Piece() = default;

    virtual const TypePiece& getTypePiece() const;
    virtual const Couleur& getCouleur() const ;
    virtual  const QString& getImage() const;
    //J'ai du enlever echequier en argument � cause de d�finition de class circulaire. �a causait des erreurs de  compilation. � la place,
    //c'est l'�ch�quier qui checkera si les d�placements sont valides ou non
    virtual std::vector<Position> getListeDeplacements(const Position& depart) const = 0;

private:
    TypePiece type_;
    Couleur couleur_;
    QString image_;
};


