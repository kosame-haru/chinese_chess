#include <iostream>
#include "include/game.h"
#include "include/version.h"

void print_status();

void Game::print_statusline() {
    print_status();
    print_version();
}

void Game::print_status() {
    std::cout << "<NO PLAYING> ";
}
