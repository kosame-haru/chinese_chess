#include <string>
#include "include/move.h"
#include "include/move_format.h"
#include "include/type.h"

std::string select_type_c(PIECE_TYPE type);

std::string move_encode(Move move) {
    std::string result = "";
    result += select_type_c(move.piece.get_type());
    result += "#";
    result += std::to_string(move.prev.x);
    result += std::to_string(move.prev.y);
    result += "-";
    result += std::to_string(move.past.x);
    result += std::to_string(move.past.y);
    return result;
}

std::string select_type_c(PIECE_TYPE type) {
    switch(type) {
        case PIECE_TYPE::KING:
            return "K";
        case PIECE_TYPE::GUARD:
            return "G";
        case PIECE_TYPE::BISHOP:
            return "B";
        case PIECE_TYPE::KNIGHT:
            return "N";
        case PIECE_TYPE::CANNON:
            return "C";
        case PIECE_TYPE::ROOK:
            return "R";
        case PIECE_TYPE::PAWN:
            return "P";
        case PIECE_TYPE::INVALID:
            return "X";
    }
    return "X";
}
