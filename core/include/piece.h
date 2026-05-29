#pragma once

#include "color.h"
#include "type.h"

class Piece {
public:
    Piece() : color(PIECE_COLOR::INVALID), type(PIECE_TYPE::INVALID) {};
    Piece(PIECE_COLOR color, PIECE_TYPE type) : color(color), type(type) {};

    bool is_red() {
        return color == PIECE_COLOR::RED;
    }

    bool is_black() {
        return color == PIECE_COLOR::BLACK;
    }

    bool is_invalid() {
        return color == PIECE_COLOR::INVALID;
    }

    bool is_equal(Piece piece) {
        return color == piece.color && type == piece.type;
    }

    PIECE_COLOR get_color() {
        return color;
    }

    PIECE_TYPE get_type() {
        return type;
    }

private:
    PIECE_COLOR color;
    PIECE_TYPE type;
};