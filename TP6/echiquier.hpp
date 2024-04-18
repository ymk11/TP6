#pragma once
#include "case.hpp"
#include <QMainWindow>



class Echiquier : public QMainWindow {
    Q_OBJECT

public:

    Echiquier(QWidget* parent = nullptr);

    void initializeBoard(); // connect(case, &Case::caseClicked, this, &Echiquier::onCaseClicked);
    const Case& getCase(const Position& position) const;
    void setCase(const Position& position, std::unique_ptr<Piece> piece);
    bool estEchec() const;
    bool isEmptyCase(const Position& position) const;


private:

    QVector<QVector<Case>> plateau_; // Représentation 2D du plateau

    Case lastSelected;

    int turns;

private slots:
    void handleButtonClick(const Position& position); // Slot to handle button clicks
};


