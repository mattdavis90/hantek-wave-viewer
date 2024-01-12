#include "vcd.hpp"
#include "utils.hpp"
#include "version.hpp"

#include <chrono>
#include <iomanip>

#include <fmt/core.h>

VCD::VCD(std::string filename, double timebase)
{
    if (timebase < 0) {
        throw std::underflow_error("Timebase must be positive");
    }

    out = std::ofstream(filename);

    auto now       = std::chrono::system_clock::now();
    auto now_time  = std::chrono::system_clock::to_time_t(now);
    auto gmt_time  = gmtime(&now_time);
    auto timestamp = std::put_time(gmt_time, "%Y-%m-%d %H:%M:%S");

    int idx = 0;
    while (timebase < 1) {
        timebase *= 1000;
        idx++;
    }

    step = 1.0;
    if (timebase > 100) {
        step     = timebase / 100;
        timebase = 100;
    } else if (timebase > 10) {
        step     = timebase / 10;
        timebase = 10;
    }

    out << "$version Hantek Wave Viewer v" << VERSION << " $end\n";
    out << "$date " << timestamp << " $end\n";
    out << "$timescale " << timebase << SMALL_UNITS[idx] << "s $end\n";
    out << "$scope module Hantek $end\n";
    out << "$var real 8 # Channel1 $end\n";
    out << "$var real 8 $ Channel2 $end\n";
    out << "$var real 8 % Channel3 $end\n";
    out << "$var real 8 & Channel4 $end\n";
    out << "$upscope $end\n";
    out << "$enddefinitions $end\n";
}

VCD::~VCD() { out.close(); }

void VCD::dump(std::optional<float> ch1, std::optional<float> ch2,
    std::optional<float> ch3, std::optional<float> ch4)
{
    if (time == 0.0) {
        out << "$dumpvars\n";
        if (ch1)
            out << fmt::format("r{:.16g} #\n", *ch1);
        if (ch2)
            out << fmt::format("r{:.16g} #\n", *ch2);
        if (ch3)
            out << fmt::format("r{:.16g} #\n", *ch3);
        if (ch4)
            out << fmt::format("r{:.16g} #\n", *ch4);
        out << "$end\n";
    } else {
        out << fmt::format("#{:.16g}\n", time);
        if (ch1)
            out << fmt::format("r{:.16g} #\n", *ch1);
        if (ch2)
            out << fmt::format("r{:.16g} #\n", *ch2);
        if (ch3)
            out << fmt::format("r{:.16g} #\n", *ch3);
        if (ch4)
            out << fmt::format("r{:.16g} #\n", *ch4);
    }
    time += step;
}