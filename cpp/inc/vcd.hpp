#pragma once

#include <fstream>
#include <optional>
#include <string>

class VCD {
public:
    VCD(std::string filename, double timebase);
    ~VCD();

    void dump(std::optional<double> ch1, std::optional<double> ch2,
        std::optional<double> ch3, std::optional<double> ch4);

private:
    std::ofstream out;
    int time = 0;
};
