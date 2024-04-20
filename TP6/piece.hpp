#pragma once
#include "couleur.hpp"
#include "typepiece.hpp"
#include "position.hpp"
#include <vector>
#include <string>
#include <QString>

namespace ui {
    class Echiquier;
}

namespace chess {
  
    class Piece {
    public:


        Piece(TypePiece type, Couleur couleur, std::string black, std::string white);
        Piece() = default;
        virtual ~Piece() = default;

        virtual const TypePiece& getTypePiece() const;
        virtual const Couleur& getCouleur() const;
        virtual  const QString& getImage() const;
        virtual std::vector<Position> getListeDeplacements(const Position& depart, const ui::Echiquier&) const = 0;

    private:
        TypePiece type_;
        Couleur couleur_;
        QString image_;
    };
}


