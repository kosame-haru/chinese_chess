#pragma once

#include <string>

void init_codepage();
void clear_screen();
void print_newline();
void set_console_color(int color);
void putchar_ex(int color, std::string c);

constexpr int TEXT_WHITE = 0x07;
constexpr int TEXT_BLUE = 0x09;
constexpr int TEXT_RED = 0x0c;
