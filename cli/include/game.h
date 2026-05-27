#pragma once

#include <string>
#include <vector>
#include "../../core/include/board.h"

class Game {
public:
    void print_statusline();
    bool exec(std::string &command);

private:
    void print_status();
    bool process(std::vector<std::string> &args);

    Board board;
    bool is_playing = false;   
};
