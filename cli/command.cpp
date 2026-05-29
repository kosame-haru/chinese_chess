#include <iostream>
#include <string>
#include <vector>

#include "../core/include/board.h"
#include "../core/include/move.h"
#include "../core/include/move_checker.h"
#include "../core/include/move_format.h"
#include "include/console.h"
#include "include/game.h"
#include "include/split.h"
#include "include/version.h"

bool Game::exec(std::string &command) {
    std::vector<std::string> args = split_command(command);
    return process(args);
}

// 返回值为 false 代表退出程序
bool Game::process(std::vector<std::string> &args) {
    if(args.size() == 0) {
        return true;
    }

    std::string main_cmd = args[0];
    if(main_cmd == "all_moves") {
        cmd_all_moves();
    } else if(main_cmd == "board") {
        cmd_board();
    } else if(main_cmd == "clear") {
        clear_screen();
    } else if(main_cmd == "quit") {
        return cmd_quit();
    } else if(main_cmd == "reverse") {
        cmd_reverse();
    } else if(main_cmd == "start") {
        cmd_start(args);
    } else if(main_cmd == "version") {
        print_version();
        print_author();
    } else {
        std::cout << "您输入了错误的命令。请输入 help 命令查看帮助。" << std::endl;
    }

    return true;
}

void Game::cmd_all_moves() {
    if(!is_playing) {
        std::cout << "对局尚未开始！" << std::endl;
        return;
    }

    MoveChecker move_checker = MoveChecker(board);
    std::vector<Move> all_moves = move_checker.generate_all_moves(board.get_side_to_move());

    for(Move move : all_moves) {
        std::cout << move_encode(move) << " ";
    }
    std::cout << std::endl;
}

void Game::cmd_board() {
    if(!is_playing) {
        std::cout << "对局尚未开始！" << std::endl;
        return;
    }

    print_board();
}

bool Game::cmd_quit() {
    if(!is_playing) {
        return false;
    }

    std::string confirm;
    std::cout << "是否要退出对局？输入yes和回车确认。 ";
    std::getline(std::cin, confirm);

    if(confirm == "yes") {
        is_playing = false;
        status = GAME_STATUS::NO_PLAYING;
        board = Board();
    }
    return true;
}

void Game::cmd_reverse() {
    if(!is_playing) {
        std::cout << "对局尚未开始！" << std::endl;
        return;
    }

    is_board_reversed = !is_board_reversed;
    print_board();
}

void Game::cmd_start(std::vector<std::string> &args) {
    if(is_playing) {
        std::cout << "对局已经开始了。" << std::endl;
        return;
    }

    std::string config;
    if(args.size() < 2) {
        config = "2p";
    } else {
        config = args[1];
    }

    is_playing = true;
    is_board_reversed = false;
    board.init();

    if(config == "2p") {
        status = GAME_STATUS::PLAYING_2P;
    } else {
        is_playing = false;
        std::cout << "命令格式：start [2p/1p/1plv1/1plv2/1plv3] [red/black]" << std::endl;
    }

    if(is_playing == true) {
        print_board();
    }
}
