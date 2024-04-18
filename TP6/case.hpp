#pragma once
#include <QPushButton>
#include "position.hpp"
#include "piece.hpp"
#include <memory>

class Case : public QPushButton {
    Q_OBJECT

public:
    Case(const Position& position, std::unique_ptr<Piece> piece, QWidget* parent = nullptr); 
    Case() = default;
    void setPiece(std::unique_ptr<Piece> newPiece); //on prend possion de l'ancienne piece : setpiece( move(oldPiece))
    const std::unique_ptr<Piece>& getPieceInfo()const; 
    std::unique_ptr<Piece> getPiece();
    const Position& getPosition() const;
    void updateAppearance();
   

signals:

    void caseClicked(const Position& position);

private slots:

    void onClicked() {}

private:
    
    Position position_;
    std::unique_ptr<Piece> piece_;
};