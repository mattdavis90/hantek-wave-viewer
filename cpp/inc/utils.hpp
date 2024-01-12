#pragma once

#include <string>

extern const std::string LARGE_UNITS[6];
extern const std::string SMALL_UNITS[6];

std::string format_large_number(double v, std::string units = "");
std::string format_small_number(double v, std::string units = "");
std::string format_number(double v, std::string units = "");
