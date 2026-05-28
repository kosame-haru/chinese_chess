#pragma once

#include <string>
#include <vector>
#include "../../core/include/board.h"

enum class GAME_STATUS {
    PLAYING_2P,
    PLAYING_1P,
    NO_PLAYING
};

class Game {
public:
    void print_statusline();
    bool exec(std::string &command);
    void print_board();

private:
    void print_status();
    void print_status2();
    bool process(std::vector<std::string> &args);

    void cmd_board();
    bool cmd_quit();
    void cmd_reverse();
    void cmd_start(std::vector<std::string> &args);

    void print_board_regular();
    void print_board_reversed();

    Board board;
    bool is_playing = false;
    bool is_board_reversed = false;
    GAME_STATUS status = GAME_STATUS::NO_PLAYING;
};
