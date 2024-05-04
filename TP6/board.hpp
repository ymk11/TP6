#pragma once
#include <vector>
#include "case.hpp"
#include "piece.hpp"
#include "king.hpp"
#include "tower.hpp"
#include "knight.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
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
        bool isColor(chess::Color color, const chess::Position& position) ;
        void selectPostions( bool select);
        std::unordered_set<chess::Position, chess::PositionHash>getAllMovements(const chess::Color& color);
        bool isCheck(const chess::Color& color);
        bool isCheckMate();
        chess::Position kingPosition(const chess::Color& color);
        std::unordered_set<chess::Position, chess::PositionHash> getFilteredMovement();
        chess::Color getInverseColor(const chess::Color& color);
        void emptyBoard();
        void setBoard(int modifier);
        void endGame();
        void setSelected(const chess::Position& position);
    private:

        std::vector<std::vector<std::unique_ptr<chess::Case>>> plateau_; 

        std::unique_ptr<chess::Position> lastSelected_ = nullptr;
        chess::Position redPosition_;

        chess::Color joueur_ = chess::Color::White;
        bool checkMate_ = true;
        bool ready_ = false;
        bool turnedRed_ = false;
        bool gameInProgress_ = false;
    

        QWidget* centralWidget_ ;
        QHBoxLayout* mainWindow_;
        QVBoxLayout* chessBoard_;

        bool isValidClick(const chess::Position& position);

    private slots:
        void handleButtonClick(const chess::Position& position); 
        void handleStartButton();
    };
}


