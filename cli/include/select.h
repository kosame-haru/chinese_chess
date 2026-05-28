#pragma once

#include <string>
#include "../../core/include/color.h"
#include "../../core/include/coord.h"
#include "../../core/include/type.h"

int select_color(PIECE_COLOR color);
std::string select_character(PIECE_COLOR color, PIECE_TYPE type, Coord coord);
