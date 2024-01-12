#include "utils.hpp"

#include <math.h>

#include <fmt/core.h>

const std::string LARGE_UNITS[6] = { "", "K", "M", "G", "T", "P" };
const std::string SMALL_UNITS[6] = { "", "m", "u", "n", "p", "f" };

std::string format_large_number(double v, std::string units)
{
    if (v == 0)
        return fmt::format("0{}", units);

    auto sign = "";
    if (v < 0) {
        v *= -1;
        sign = "-";
    }

    auto i = 0;
    while (v >= 1000 && i < 5) {
        v /= 1000;
        i++;
    }

    return fmt::format("{}{}{}{}", sign, v, LARGE_UNITS[i], units);
}

std::string format_small_number(double v, std::string units)
{
    if (v == 0)
        return fmt::format("0{}", units);

    auto sign = "";
    if (v < 0) {
        v *= -1;
        sign = "-";
    }

    auto i = 0;
    while (v < 1 && i < 5) {
        v *= 1000;
        i++;
    }
    auto d = int(v);

    return fmt::format("{}{}{}{}", sign, d, SMALL_UNITS[i], units);
}

std::string format_number(double v, std::string units)
{
    if (fabs(v) > 1)
        return format_large_number(v, units);
    return format_small_number(v, units);
}
