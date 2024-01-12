#pragma once

#include <fstream>
#include <optional>
#include <string>

class VCD {
public:
    VCD(std::string filename, double timebase);
    ~VCD();

    void dump(std::optional<float> ch1, std::optional<float> ch2,
        std::optional<float> ch3, std::optional<float> ch4);

private:
    std::ofstream out;
    float step = 0.0;
    float time = 0.0;
};
