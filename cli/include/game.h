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

private:
    void print_status();
    bool process(std::vector<std::string> &args);

    bool cmd_quit();
    void cmd_start(std::vector<std::string> &args);

    Board board;
    bool is_playing = false;
    GAME_STATUS status = GAME_STATUS::NO_PLAYING;
};
