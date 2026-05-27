#include <iostream>
#include "./include/statusline.h"
#include "./include/version.h"

void print_status();

void print_statusline() {
    print_status();
    print_version();
}

void print_status() {
    std::cout << "<NO PLAYING> ";
}