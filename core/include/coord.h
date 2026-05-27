#pragma once

struct Coord {
    Coord() : x(0), y(0) {};
    Coord(int x, int y) : x(x), y(y) {};
    
    int x, y;
};
