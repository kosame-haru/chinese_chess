#include <string>
#include <vector>
#include "include/split.h"

std::string trim_command(std::string &command);
std::vector<std::string> split_trimed_command(std::string &command);

std::vector<std::string> split_command(std::string &command) {
    std::string trimed_command = trim_command(command);
    return split_trimed_command(trimed_command);
}

std::string trim_command(std::string &command) {
    size_t start = command.find_first_not_of(" ");
    size_t end = command.find_last_not_of(" ");
    return (start == std::string::npos) ? "" : command.substr(start, end-start+1);
}

enum class SPLIT_STATUS {
    CHARACTER,
    SPACE
};

std::vector<std::string> split_trimed_command(std::string &command) {
    std::vector<std::string> args;
    if(command == "") {
        return args;
    }

    std::string str = "";
    SPLIT_STATUS status = SPLIT_STATUS::CHARACTER;
    for(char c : command) {
        switch(status) {
            case SPLIT_STATUS::CHARACTER:
                if(c == ' ') {
                    status = SPLIT_STATUS::SPACE;
                    args.push_back(str);
                    str = "";
                } else {
                    str += c;
                }
                break;
            
            case SPLIT_STATUS::SPACE:
                if(c != ' ') {
                    status = SPLIT_STATUS::CHARACTER;
                    str += c;
                }
                break;
        }
    }

    args.push_back(str);
    return args;
}
