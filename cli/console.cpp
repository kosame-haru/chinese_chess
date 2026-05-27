#include <iostream>
#include <cstdlib>
#include "include/console.h"

void init_codepage() {
    system("chcp 65001");
}

void clear_screen() {
    system("cls");
}

void print_newline() {
    std::cout << std::endl;
}
