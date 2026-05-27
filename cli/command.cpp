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
        return false;
    } else if(main_cmd == "version") {
        print_version();
        print_author();
    } else {
        int size = args.size();
        std::cout << "argc = " << size << std::endl;

        for(int i = 0; i < size; i++) {
            std::cout << "argv[" << i << "] = \"" << args[i] << "\"" << std::endl; 
        }
    }

    return true;
}