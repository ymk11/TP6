#pragma once
#include <QPushButton>
#include "piece.hpp"
#include <memory>
#include  <QPalette>



namespace chess {
    class Case : public QPushButton {
        Q_OBJECT

    public:
        Case(const Couleur& color, const Position& position, std::unique_ptr<Piece> piece, QWidget* parent = nullptr);
        Case(const Couleur& color, const Position& position, QWidget* parent = nullptr);
        Case() = default;
        void setPiece(std::unique_ptr<Piece> newPiece, bool update = false); //on prend possion de l'ancienne piece : setpiece( move(oldPiece))
        const std::unique_ptr<Piece>& getPieceInfo()const;
        std::unique_ptr<Piece> getPiece();
        const Position& getPosition() const;
        void updateAppearance();
        void setSelect(bool select);


    signals:

        void caseClicked(const Position& position);

    private slots:

        void onClicked();

    private:

        Position position_ ;
        std::unique_ptr<Piece> piece_ = nullptr;
        QString style_;
    };
}