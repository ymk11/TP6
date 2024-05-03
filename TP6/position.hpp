#pragma once
#include <unordered_set>

namespace chess {

    

    class Position {
    public:

        Position();
        Position(int x, int y);
        Position(const Position& other);
        bool estValide() const;
        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);
        bool operator==(const Position& other)const ;
        Position& operator=(const Position& other);
        
    private:
        int x_;
        int y_;
       
    };

    struct PositionHash {
        size_t operator()(const Position& position) const;
    };
}


