#ifndef POSITION_H
#define POSITION_H

#include <iostream>
#pragma once

class Position {
public:

    Position();
    Position(int x, int y);
    bool estValide() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
private:
    int x;
    int y;
};

#endif // POSITION_H
