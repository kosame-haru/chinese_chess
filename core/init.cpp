#include "include\board.h"
#include "include\color.h"
#include "include\coord.h"
#include "include\piece.h"
#include "include\type.h"

void Board::init() {
    set_piece(Coord(4,0), Piece(PIECE_COLOR::BLACK, PIECE_TYPE::KING));
    set_piece(Coord(4,9), Piece(PIECE_COLOR::RED, PIECE_TYPE::KING));

    PIECE_TYPE type_table[4] = { PIECE_TYPE::ROOK, PIECE_TYPE::KNIGHT, PIECE_TYPE::BISHOP, PIECE_TYPE::GUARD };
    for(int i = 0; i < 4; i++) {
        PIECE_TYPE type = type_table[i];

        set_piece(Coord(i,0), Piece(PIECE_COLOR::BLACK, type));
        set_piece(Coord(8-i,0), Piece(PIECE_COLOR::BLACK, type));
        set_piece(Coord(i,9), Piece(PIECE_COLOR::RED, type));
        set_piece(Coord(8-i,9), Piece(PIECE_COLOR::RED, type));
    }

    set_piece(Coord(1,2), Piece(PIECE_COLOR::BLACK, PIECE_TYPE::CANNON));
    set_piece(Coord(7,2), Piece(PIECE_COLOR::BLACK, PIECE_TYPE::CANNON));
    set_piece(Coord(1,7), Piece(PIECE_COLOR::RED, PIECE_TYPE::CANNON));
    set_piece(Coord(7,7), Piece(PIECE_COLOR::RED, PIECE_TYPE::CANNON));

    for(int i = 0; i < 5; i++) {
        set_piece(Coord(i*2,3), Piece(PIECE_COLOR::BLACK, PIECE_TYPE::PAWN));
        set_piece(Coord(i*2,6), Piece(PIECE_COLOR::RED, PIECE_TYPE::PAWN));
    }
}
