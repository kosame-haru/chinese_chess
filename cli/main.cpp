#include <iostream>
#include <string>

#include "include/console.h"
#include "include/game.h"
#include "include/version.h"

void print_welcome();

int main() {
    init_codepage();
    clear_screen();
    print_welcome();

    Game game = Game();
    while(true) {    
        game.print_statusline();
        std::cout << "$ ";

        std::string command;
        std::getline(std::cin, command);
        if(!game.exec(command)) {
            break;
        }

        print_newline();
    }
}

void print_welcome() {
    std::cout << "欢迎光临！我是小雨はる。" << std::endl;
    std::cout << "使用 start 命令快速开始一场对局，使用 help 命令查看其它功能。" << std::endl;
    std::cout << "或者查看我们的文档，了解更多信息。" << std::endl;
    std::cout << std::endl;
}
