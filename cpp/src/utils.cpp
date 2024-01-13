#include "utils.hpp"

#include <math.h>

#include <doctest/doctest.h>
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

TEST_CASE("testing format_number")
{
    CHECK(format_number(10000000000) == "10G");
    CHECK(format_number(1000000000) == "1G");
    CHECK(format_number(100000000) == "100M");
    CHECK(format_number(10000000) == "10M");
    CHECK(format_number(1000000) == "1M");
    CHECK(format_number(100000) == "100K");
    CHECK(format_number(10000) == "10K");
    CHECK(format_number(1000) == "1K");
    CHECK(format_number(100) == "100");
    CHECK(format_number(10) == "10");
    CHECK(format_number(1) == "1");
    CHECK(format_number(0.1) == "100m");
    CHECK(format_number(0.01) == "10m");
    CHECK(format_number(0.001) == "1m");
    CHECK(format_number(0.0001) == "100u");
    CHECK(format_number(0.00001) == "10u");
    CHECK(format_number(0.000001) == "1u");
}
