#include <iostream>
#include <string>

#include "./include/console.h"
#include "./include/statusline.h"
#include "./include/version.h"

int main() {
    init_codepage();
    clear_screen();

    while(true) {    
        print_statusline();
        std::cout << "$ ";

        std::string command;
        std::getline(std::cin, command);

        if(command == "quit") {
            break;
        } else if(command == "version") {
            print_version();
            print_author();
        }

        print_newline();
    }
}
