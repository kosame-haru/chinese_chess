#include <iostream>

#include <vector>
#include "include/board.h"
#include "include/color.h"
#include "include/coord.h"
#include "include/move.h"
#include "include/move_checker.h"
#include "include/type.h"

void vector_append(std::vector<Move> &moves, std::vector<Move> moves_sub);

std::vector<Move> MoveChecker::generate_all_moves(PIECE_COLOR color) {
    return generate_all_moves_raw(color);
}

std::vector<Move> MoveChecker::generate_all_moves_raw(PIECE_COLOR color) {
    std::vector<Move> moves;

    for(int y = 0; y < BOARD_HEIGHT; y++) {
        for(int x = 0; x < BOARD_WIDTH; x++) {
            Piece piece = *(board.get_piece(Coord(x, y)));

            if(piece.get_color() == color) {
                switch(piece.get_type()) {
                    case PIECE_TYPE::ROOK:
                        vector_append(moves, generate_rook_moves(Coord(x, y)));
                        break;
                    case PIECE_TYPE::CANNON:
                        vector_append(moves, generate_cannon_moves(Coord(x, y)));
                }
            }
        }
    }

    return moves;
}

void vector_append(std::vector<Move> &moves, std::vector<Move> moves_sub) {
    for(Move move : moves_sub) {
        moves.push_back(move);
    }
}

std::vector<Move> MoveChecker::generate_rook_moves(Coord coord) {
    std::vector<Move> moves;
    
    std::vector<Coord> directions = {
        Coord(1,0), Coord(-1,0), Coord(0,1), Coord(0,-1)
    };

    for(Coord direction : directions) {
        Coord current_coord = coord;
        MOVE_STATUS status = MOVE_STATUS::MOVE;

        while(true) {
            current_coord.x += direction.x;
            current_coord.y += direction.y;

            status = rook_move_checker(current_coord, status);
            if(status == MOVE_STATUS::STOP) {
                break;
            }

            Piece piece = *(board.get_piece(coord));
            moves.push_back(Move(piece, coord, current_coord));
        }
    }

    return moves;
}

std::vector<Move> MoveChecker::generate_cannon_moves(Coord coord) {
    std::vector<Move> moves;

    std::vector<Coord> directions = {
        Coord(1,0), Coord(-1,0), Coord(0,1), Coord(0,-1)
    };

    for(Coord direction : directions) {
        Coord current_coord = coord;
        MOVE_STATUS status = MOVE_STATUS::MOVE;

        while(true) {
            current_coord.x += direction.x;
            current_coord.y += direction.y;

            status = cannon_move_checker(current_coord, status);
            if(status == MOVE_STATUS::STOP) {
                break;
            } else if(status == MOVE_STATUS::MOVE || status == MOVE_STATUS::CAPTURE) {
                Piece piece = *(board.get_piece(coord));
                moves.push_back(Move(piece, coord, current_coord));
            }
        }
    }

    return moves;
}

MOVE_STATUS MoveChecker::rook_move_checker(Coord coord, MOVE_STATUS status) {
    if(!Board::is_valid_coord(coord)) {
        return MOVE_STATUS::STOP;
    }

    if(status == MOVE_STATUS::CAPTURE) {
        return MOVE_STATUS::STOP;
    }

    Piece piece = *(board.get_piece(coord));
    PIECE_COLOR side_to_move = board.get_side_to_move();
    PIECE_COLOR current_color = piece.get_color();

    if(current_color == PIECE_COLOR::INVALID) {
        return MOVE_STATUS::MOVE;
    } else if(current_color == side_to_move) {
        return MOVE_STATUS::STOP;
    } else {
        return MOVE_STATUS::CAPTURE;
    }
}

MOVE_STATUS MoveChecker::cannon_move_checker(Coord coord, MOVE_STATUS status) {
    if(!Board::is_valid_coord(coord)) {
        return MOVE_STATUS::STOP;
    }

    if(status == MOVE_STATUS::CAPTURE) {
        return MOVE_STATUS::STOP;
    }

    Piece piece = *(board.get_piece(coord));
    PIECE_COLOR side_to_move = board.get_side_to_move();
    PIECE_COLOR current_color = piece.get_color();

    if(status == MOVE_STATUS::MOVE) {
        if(current_color == PIECE_COLOR::INVALID) {
            return MOVE_STATUS::MOVE;
        } else {
            return MOVE_STATUS::CANNON_CLIMBED;
        }
    } else {
        /* CANNON_CLIMBED */
        if(current_color == PIECE_COLOR::INVALID) {
            return MOVE_STATUS::CANNON_CLIMBED;
        } else if(current_color == side_to_move) {
            return MOVE_STATUS::STOP;
        } else {
            return MOVE_STATUS::CAPTURE;
        }
    }
}
