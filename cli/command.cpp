#include <iostream>
#include <string>
#include <vector>
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
    if(main_cmd == "quit") {
        return cmd_quit();
    } else if(main_cmd == "start") {
        cmd_start(args);
    } else if(main_cmd == "version") {
        print_version();
        print_author();
    }

    return true;
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
    }
    return true;
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
    // board.init();
    if(config == "2p") {
        status = GAME_STATUS::PLAYING_2P;
    } else {
        is_playing = false;
        std::cout << "命令格式：start [2p/1p/1plv1/1plv2/1plv3]" << std::endl;
    }
}
