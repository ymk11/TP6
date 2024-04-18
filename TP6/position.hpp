#pragma once
#include <iostream>
#include <cassert>
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
    int x_;
    int y_;
};


