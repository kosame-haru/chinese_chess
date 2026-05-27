#include <string>
#include <vector>
#include "include/split.h"

std::string trim_command(std::string &command);
std::vector<std::string> split_trimed_command(std::string &command);

std::vector<std::string> split_command(std::string command) {
    std::string trimed_command = trim_command(command);
    return split_trimed_command(trimed_command);
}

std::string trim_command(std::string &command) {
    size_t start = command.find_first_not_of(" ");
    size_t end = command.find_last_not_of(" ");
    return (start == std::string::npos) ? "" : command.substr(start, end-start+1);
}

std::vector<std::string> split_trimed_command(std::string &command) {
    std::vector<std::string> args;
    args.push_back(command);
    return args;
}