#include <string>
#include "include/game.h"
#include "include/version.h"

// 返回值为 false 代表退出程序
bool Game::exec(std::string command) {
    if(command == "quit") {
        return false;
    } else if(command == "version") {
        print_version();
        print_author();
    }

    return true;
}
