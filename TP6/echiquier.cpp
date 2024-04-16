//#include "Echiquier.hpp"
//#include <iostream>
//#pragma once
//
//Echiquier::Echiquier() {
//
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            plateau[i][j] = nullptr; //  vide
//        }
//    }
//}
//
//Piece* Echiquier::getPiece(const Position& position) const {
//    if (estDansLimitesEchiquier(position)) {
//        return plateau[position.y][position.x];
//    }
//    else {
//        return nullptr; //  hors du plateau
//    }
//}
//
//void Echiquier::setPiece(const Position& position, Piece* piece) {
//    if (estDansLimitesEchiquier(position)) {
//        plateau[position.y][position.x] = piece;
//    }
//}
//
//bool Echiquier::estEchec() const {
//    // to do ...
//}
//
//bool Echiquier::estDansLimitesEchiquier(const Position& position) const {
//    return position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8;
//}
//
//
