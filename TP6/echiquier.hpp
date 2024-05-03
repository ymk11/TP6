#pragma once
#include <vector>
#include "case.hpp"
#include "piece.hpp"
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QMainWindow>


namespace ui {
    class Board : public QMainWindow {
        Q_OBJECT

    public:

        Board(QWidget* parent = nullptr);
        void initializeBoard(); 
        void initializeMenu();
        chess::Case& getCase(const chess::Position& position) ;
        void setCase(const chess::Position& position, std::unique_ptr<chess::Piece> piece);
        bool isEmptyCase(const chess::Position& position) ;
        void moveTo(const chess::Position& start, const chess::Position& destination, bool display = false);
        void moveToValid(const chess::Position& start, const chess::Position& destination);
        bool isColor(chess::Couleur color, const chess::Position& position) ;
        void selectPostions( bool select);
        std::unordered_set<chess::Position, chess::PositionHash>getAllMovements(const chess::Couleur& color);
        bool isCheck(const chess::Couleur& color);
        bool isCheckMate();
        chess::Position kingPosition(const chess::Couleur& color);
        std::unordered_set<chess::Position, chess::PositionHash> getFilteredMovement();
        chess::Couleur getInverseColor(const chess::Couleur& color);
        void emptyBoard();
        void setBoard(int modifier);
        void endGame();
    private:

        std::vector<std::vector<std::unique_ptr<chess::Case>>> plateau_; // Représentation 2D du plateau

        std::unique_ptr<chess::Position> lastSelected_ = nullptr;
        chess::Position redPosition_;

        chess::Couleur joueur_ = chess::Couleur::White;
        bool checkMate_ = true;
        bool ready_ = false;
        bool turnedRed_ = false;
        bool gameInProgress_ = false;
    

        QWidget* centralWidget_ ;
        QHBoxLayout* mainWindow_;
        QVBoxLayout* chessBoard_;

        bool isValidClick(const chess::Position& position);

    private slots:
        void handleButtonClick(const chess::Position& position); // Slot to handle button clicks
        void handleStartButton();
    };
}


