#pragma once
#include <cassert>

namespace chess {
    class Position {
    public:

        Position();
        Position(int x, int y);
        bool estValide() const;
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        bool operator==(const Position other);
    private:
        int x_;
        int y_;
       
    };
}


