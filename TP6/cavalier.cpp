#pragma once
#include "cavalier.hpp"
#include "echiquier.hpp"
#include <ranges>


namespace chess {
    Cavalier::Cavalier(Couleur couleur) : Piece(TypePiece::Cavalier,
        couleur, "..\\assets\\nd.png", "..\\assets\\nl.png") {}

   

    std::unordered_set<Position, PositionHash> Cavalier::getListeDeplacements(const Position& start,  ui::Echiquier& echiquier) const {
        std::unordered_set<Position, PositionHash> positions;
        positions.insert(Position(start.getX()+2, start.getY()+1));
        positions.insert(Position(start.getX()+1, start.getY() +2));
        positions.insert(Position(start.getX()+2, start.getY()-1));
        positions.insert(Position(start.getX()+1, start.getY()-2));

        positions.insert(Position(start.getX()-2, start.getY()-1));
        positions.insert(Position(start.getX()-1, start.getY()-2));
        positions.insert(Position(start.getX()-2, start.getY()+1));
        positions.insert(Position(start.getX()-1, start.getY()+2));
        erase_if(positions, [&echiquier, this] (const Position& pos) {
            if (pos.estValide()) {
                if (!echiquier.isEmptyCase(pos)) {
                    return echiquier.isColor(Piece::getCouleur(), pos);
                }
                return false;
            } 
            return true;
            
            });
        return positions;
    }
}
