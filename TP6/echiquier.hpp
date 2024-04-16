#pragma once
#ifndef ECHEQUIER_H
#define ECHEQUIER_H
#include <vector>
#include "case.hpp"
#include <iostream>
#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#pragma once

class Echiquier : public QMainWindow {
    Q_OBJECT
public:
    Echiquier(QWidget* parent = nullptr);
    void initializeBoard(); // connect(case, &Case::caseClicked, this, &Echiquier::onCaseClicked);
    const Case& getCase(const Position& position) const;
    void setCase(const Position& position, Piece* piece);
    bool estEchec() const;
    bool emptyCase(const Position& position);

private:
    void onCaseClicked(const Position& pos);

    QVector<QPushButton*> cases; // Représentation 2D du plateau
    QGridLayout* layout;
    Case lastSelectedP1;
    Case lastSelectedP2;
    int turns;

private slots:
    void handleButtonClick(); // Slot to handle button clicks
};

#endif // ECHEQUIER_H
