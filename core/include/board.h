#pragma once

#include <array>
#include <optional>

#include "coord.h"
#include "color.h"
#include "piece.h"

constexpr int BOARD_WIDTH = 9;
constexpr int BOARD_HEIGHT = 10;

class Board {
public:
    static bool is_valid_coord(Coord coord) {
        if(coord.x < 0 || coord.x > BOARD_WIDTH) {
            return false;
        }

        if(coord.y < 0 || coord.y > BOARD_HEIGHT) {
            return false;
        }

        return true;
    }

    std::optional<Piece> get_piece(Coord coord) {
        if(!Board::is_valid_coord(coord)) {
            return std::nullopt;
        }

        Piece piece = pieces[coord.x][coord.y];
        return {piece};
    }

    bool set_piece(Coord coord, Piece piece) {
        if(!Board::is_valid_coord(coord)) {
            return false;
        }

        pieces[coord.x][coord.y] = piece;
        return true;
    }

    bool move_piece(Coord prev, Coord past) {
        auto piece_opt = get_piece(prev);
        if(!piece_opt) {
            return false;
        }
        Piece piece = *piece_opt;

        if(!Board::is_valid_coord(past)) {
            return false;
        }
        set_piece(past, piece);
        set_piece(prev, Piece());

        return true;
    }

    void init();

private:
    std::array<std::array<Piece, BOARD_HEIGHT>, BOARD_WIDTH> pieces; 
    PIECE_COLOR side_to_move = PIECE_COLOR::RED;
    int steps = 0;
};
