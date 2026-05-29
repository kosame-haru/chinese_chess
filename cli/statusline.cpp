#include <iostream>
#include "../core/include/board.h"
#include "../core/include/color.h"
#include "include/game.h"
#include "include/version.h"

void Game::print_statusline() {
    print_status();

    if(!is_playing) {
        print_version();
    } else {
        print_status2();
    }
}

void Game::print_status() {
    if(is_playing) {
        std::cout << "<";

        switch(board.get_side_to_move()) {
            case PIECE_COLOR::RED:
                std::cout << "RED";
                break;

            case PIECE_COLOR::BLACK:
                std::cout << "BLACK";
                break;

            default:
                std::cout << "INVALID";
        }

        std::cout << "%step " << board.get_steps() << "> ";
    } else {
        std::cout << "<NO PLAYING> ";
    }
}

void Game::print_status2() {
    std::cout << "INIT (playing)" << std::endl;
}
