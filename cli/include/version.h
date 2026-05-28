#pragma once

#include <string>

constexpr int VERSION_NUMBER = 1;
constexpr int SUBVER_NUMBER = 0;
constexpr int BUILD_NUMBER = 7;

const std::string STAGE = "Milestone 1";
const std::string AUTHOR = "kosame haru（小雨はる）";

void print_version();
void print_author();