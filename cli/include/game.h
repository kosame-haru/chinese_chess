#pragma once

#include <string>
#include "../../core/include/board.h"

class Game {
public:
    void print_statusline();
    bool exec(std::string command);

private:
    void print_status();

    Board board;
    bool is_playing = false;   
};
