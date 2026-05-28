#include <vector>
#include <string>

#include "../core/include/board.h"
#include "../core/include/color.h"
#include "../core/include/coord.h"
#include "../core/include/type.h"
#include "include/console.h"
#include "include/select.h"

constexpr int KING = 0;
constexpr int GUARD = 1;
constexpr int BISHOP = 2;
constexpr int KNIGHT = 3;
constexpr int CANNON = 4;
constexpr int ROOK = 5;
constexpr int PAWN = 6;
constexpr int TYPE_INVALID = 7;

constexpr int RED = 0;
constexpr int BLACK = 1;
constexpr int COLOR_INVALID = 2;

int convert_color_code(PIECE_COLOR color);
int convert_type_code(PIECE_TYPE type);

int select_color(PIECE_COLOR color) {
    switch(color) {
        case PIECE_COLOR::RED:
            return TEXT_RED;
        case PIECE_COLOR::BLACK:
            return TEXT_BLUE;
        case PIECE_COLOR::INVALID:
            return TEXT_WHITE;
    }
    return 0;
}

std::string select_character(PIECE_COLOR color, PIECE_TYPE type, Coord coord) {
    int color_code = convert_color_code(color);
    int type_code = convert_type_code(type);

    std::vector<std::vector<std::string>> character_table = {
        {"帥", "仕", "相", "馬", "炮", "車", "兵", "・"},
        {"将", "士", "象", "馬", "炮", "車", "卒", "・"},
        {"・", "・", "・", "・", "・", "・", "・", "・"}
    };
    std::string character = character_table[color_code][type_code];

    if(type == PIECE_TYPE::INVALID) {
        if(coord.y == 4 || coord.y == 5) {
            character = "〇";
        } else if(Board::is_in_castle(coord)) {
            character = "ロ";
        }
    }

    return character;
}

int convert_color_code(PIECE_COLOR color) {
    switch(color) {
        case PIECE_COLOR::RED:
            return RED;
        case PIECE_COLOR::BLACK:
            return BLACK;
        case PIECE_COLOR::INVALID:
            return COLOR_INVALID;
    }
    return 0;
}

int convert_type_code(PIECE_TYPE type) {
    switch(type) {
        case PIECE_TYPE::KING:
            return KING;
        case PIECE_TYPE::GUARD:
            return GUARD;
        case PIECE_TYPE::BISHOP:
            return BISHOP;
        case PIECE_TYPE::KNIGHT:
            return KNIGHT;
        case PIECE_TYPE::CANNON:
            return CANNON;
        case PIECE_TYPE::ROOK:
            return ROOK;
        case PIECE_TYPE::PAWN:
            return PAWN;
        case PIECE_TYPE::INVALID:
            return TYPE_INVALID;
    }
    return 0;
}
