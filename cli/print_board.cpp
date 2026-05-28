#include <iostream>
#include <string>

#include "..\core\include\piece.h"
#include "include\console.h"
#include "include\game.h"
#include "include\select.h"

void Game::print_board() {
    print_board_regular();
}

void Game::print_board_regular() {
    print_newline();
    
    std::string title = "　０１２３４５６７８";
    std::cout << title << std::endl;

    std::vector<std::string> row_table = {
        "０", "１", "２", "３", "４", 
        "５", "６", "７", "８", "９"
    };

    for(int y = 0; y < BOARD_HEIGHT; y++) {
        putchar_ex(TEXT_WHITE, row_table[y]);
        for(int x = 0; x < BOARD_WIDTH; x++) {
            Piece piece = *(board.get_piece(Coord(x, y)));
            putchar_ex(select_color(piece.get_color()), select_character(piece.get_color(), piece.get_type(), Coord(x,y)));            
        }
        print_newline();
    }
    set_console_color(TEXT_WHITE);
}
