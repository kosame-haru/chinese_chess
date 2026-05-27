#pragma once

#include "coord.h"
#include "piece.h"

struct Move {
    Move(Piece piece, Coord prev, Coord past) : piece(piece), prev(prev), past(past) {};

    Piece piece;
    Coord prev, past;
};
