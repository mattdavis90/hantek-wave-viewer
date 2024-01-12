#pragma once

#include "hantek_parser.hpp"

#include <cstring>
#include <fstream>
#include <iostream>
#include <optional>
#include <tuple>

class Hantek {
public:
    Hantek(const std::string filename);
    void print(std::ostream& os = std::cout);

    double timebase();
    std::tuple<std::optional<double>, std::optional<double>, std::optional<double>,
        std::optional<double>>
    next();

    void reset();

private:
    std::unique_ptr<hantek_t> h;
    size_t idx = 0;

    void print_header(std::ostream& os);
    void print_channel(std::ostream& os, int n, const hantek_t::channel_t* ch);
    std::optional<double> get_data(
        size_t idx, const hantek_t::channel_t* ch, const std::vector<int16_t>* data);

public:
    const double TIMEBASE[33] = {
        2e-9,
        5e-9,
        10e-9,
        20e-9,
        50e-9,
        100e-9,
        200e-9,
        500e-9,
        1e-6,
        2e-6,
        5e-6,
        10e-6,
        20e-6,
        50e-6,
        100e-6,
        200e-6,
        500e-6,
        1e-3,
        2e-3,
        5e-3,
        10e-3,
        20e-3,
        50e-3,
        100e-3,
        200e-3,
        500e-3,
        1,
        2,
        5,
        10,
        20,
        50,
        100,
    };
    const double VOLTS_PER_DIV[14] = {
        500e-6,
        1e-3,
        2e-3,
        5e-3,
        10e-3,
        20e-3,
        50e-3,
        100e-3,
        200e-3,
        500e-3,
        1,
        2,
        5,
        10,
    };
    const std::string TRIGGER_NAME[14] = {
        "Edge",
        "Pulse",
        "Video",
        "Slope",
        "Overtime",
        "Window",
        "Pattern",
        "Interval",
        "Under Amp",
        "UART",
        "LIN",
        "CAN",
        "SPI",
        "IIC",
    };
    const std::string ACQUISITION_MODE[4] = { "Normal", "Average", "Peak", "HR" };
};
