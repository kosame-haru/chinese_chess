#pragma once

struct Coord {
    Coord() : x(0), y(0) {};
    Coord(const int x, const int y) : x(x), y(y) {};
    
    int x, y;
};
