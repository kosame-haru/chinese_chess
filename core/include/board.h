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
    static bool is_valid_coord(const Coord coord) {
        if(coord.x < 0 || coord.x > BOARD_WIDTH) {
            return false;
        }

        if(coord.y < 0 || coord.y > BOARD_HEIGHT) {
            return false;
        }

        return true;
    }

    std::optional<Piece> get_piece(const Coord coord) {
        if(!Board::is_valid_coord(coord)) {
            return std::nullopt;
        }

        Piece piece = pieces[coord.x][coord.y];
        return {piece};
    }

    bool set_piece(const Coord coord, const Piece piece) {
        if(!Board::is_valid_coord(coord)) {
            return false;
        }

        pieces[coord.x][coord.y] = piece;
        return true;
    }

    void clear_board() {
        for(int x = 0; x < 9; x++) {
            for(int y = 0; y < 10; y++) {
                set_piece(Coord(x,y), Piece());
            }
        }
    }

    bool move_piece(const Coord prev, const Coord past) {
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

private:
    std::array<std::array<Piece, 10>, 9> pieces; 
    PIECE_COLOR side_to_move = PIECE_COLOR::RED;
};
