#pragma once
#include <vector>
#include "case.hpp"
#include "piece.hpp"
#include <QMainWindow>

namespace ui {
    class Echiquier : public QMainWindow {
        Q_OBJECT

    public:

        Echiquier(QWidget* parent = nullptr);
        Echiquier() = default;

        void initializeBoard(); // connect(case, &Case::caseClicked, this, &Echiquier::onCaseClicked);
        chess::Case& getCase(const chess::Position& position) ;
        void setCase(const chess::Position& position, std::unique_ptr<chess::Piece> piece);
        bool estEchec() const;
        bool isEmptyCase(const chess::Position& position) ;
        void moveTo(const chess::Position& start, const chess::Position& destination);


    private:

        std::vector<std::vector<chess::Case>> plateau_; // Représentation 2D du plateau

        chess::Case lastSelected;

        int turn;

    private slots:
        void handleButtonClick(const chess::Position& position); // Slot to handle button clicks
    };
}


