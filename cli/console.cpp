#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
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

void set_console_color(int color) {
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void putchar_ex(int color, std::string c) {
    set_console_color(color);
    std::cout << c;
	return;
}
