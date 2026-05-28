#include <iostream>
#include "include/version.h"

void print_version() {
    std::cout << "Chinese Chess v" << VERSION_NUMBER << "." << SUBVER_NUMBER;
    std::cout << ", build " << BUILD_NUMBER << " (" << STAGE << ")" << std::endl;
}

void print_author() {
    std::cout << "作者：" << AUTHOR << std::endl;
}
