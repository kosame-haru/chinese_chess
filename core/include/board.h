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
        if(coord.x < 0 || coord.x >= BOARD_WIDTH) {
            return false;
        }

        if(coord.y < 0 || coord.y >= BOARD_HEIGHT) {
            return false;
        }

        return true;
    }

    static bool is_in_castle(Coord coord) {
        return is_in_red_castle(coord) | is_in_black_castle(coord);
    }

    bool is_in_current_castle(Coord coord) {
        switch(side_to_move) {
            case PIECE_COLOR::RED:
                return is_in_red_castle(coord);
            case PIECE_COLOR::BLACK:
                return is_in_black_castle(coord);
            case PIECE_COLOR::INVALID:
                return false;
        }
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

    int get_steps() {
        return steps;
    }

    PIECE_COLOR get_side_to_move() {
        return side_to_move;
    }

    void init();

private:
    static bool is_in_red_castle(Coord coord) {
        if(coord.x < 3 || coord.x > 5) {
            return false;
        }

        if(coord.y > 2) {
            return false;
        }

        return true;
    }

    static bool is_in_black_castle(Coord coord) {
        if(coord.x < 3 || coord.x > 5) {
            return false;
        }

        if(coord.y < BOARD_HEIGHT-3) {
            return false;
        }

        return true;
    }

    std::array<std::array<Piece, BOARD_HEIGHT>, BOARD_WIDTH> pieces; 
    PIECE_COLOR side_to_move = PIECE_COLOR::RED;
    int steps = 0;
};
