#pragma once

#include "../../core/include/board.h"

class Game {
public:
    void print_statusline();

private:
    void print_status();

    Board board;
    bool is_playing = false;   
};
