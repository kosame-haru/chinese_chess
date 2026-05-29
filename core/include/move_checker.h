#pragma once

#include <vector>
#include "board.h"
#include "coord.h"
#include "move.h"

enum class MOVE_STATUS {
    MOVE,
    STOP,
    CAPTURE,
    CANNON_CLIMBED
};

class MoveChecker {
public:
    MoveChecker() = delete;
    MoveChecker(Board board) : board(board) {};

    std::vector<Move> generate_all_moves(PIECE_COLOR color);
private:
    std::vector<Move> generate_rook_moves(Coord coord);

    MOVE_STATUS rook_move_checker(Coord coord, MOVE_STATUS status);

    Board board;
};
