#pragma once
#include "color.hpp"
#include "typepiece.hpp"
#include "position.hpp"
#include <unordered_set>
#include <string>
#include <QString>
#include <algorithm>

namespace ui {
    class Board;
}

namespace chess {
  
    class Piece {
    public:


        Piece(TypePiece type, Color couleur, std::string black, std::string white);
        Piece() = default;
        virtual ~Piece() = default;

        virtual const TypePiece& getTypePiece() const;
        virtual const Color& getColor() const;
        virtual  const QString& getImage() const;
        virtual std::unordered_set <Position, PositionHash> getMovementsList(const Position& depart, ui::Board& echiquier) const = 0;

    private:
        TypePiece type_;
        Color color_;
        QString image_;
    };
}


