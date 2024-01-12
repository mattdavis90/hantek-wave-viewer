#include "hantek.hpp"
#include "utils.hpp"

#include <math.h>

#include <fmt/core.h>
#include <rang.hpp>

Hantek::Hantek(const std::string filename)
{
    std::ifstream fs(filename, std::ios::binary);
    if (fs.is_open()) {
        kaitai::kstream ks(&fs);
        this->h = std::unique_ptr<hantek_t>(new hantek_t(&ks));
        fs.close();
    } else if (fs.fail()) {
        throw std::runtime_error(
            fmt::format("Could not open file: {}", std::strerror(errno)));
        std::cout << "Could not open file: " << std::strerror(errno) << std::endl;
    } else {
        std::cout << "Unknown error when opening file" << std::endl;
    }
}

void Hantek::print(std::ostream& os)
{
    print_header(os);

    print_channel(os, 1, h->header()->channel1());
    print_channel(os, 2, h->header()->channel2());
    print_channel(os, 3, h->header()->channel3());
    print_channel(os, 4, h->header()->channel4());

    os << rang::fg::magenta << "Data:" << rang::style::reset << "\n";
    os << "\tChannel 1: " << format_number(h->data1()->size()) << "\n";
    os << "\tChannel 2: " << format_number(h->data2()->size()) << "\n";
    os << "\tChannel 3: " << format_number(h->data3()->size()) << "\n";
    os << "\tChannel 4: " << format_number(h->data4()->size()) << "\n";
    os << std::flush;
}

void Hantek::print_header(std::ostream& os)
{
    os << rang::fg::magenta << "Common:" << rang::style::reset << "\n";
    os << "\tVersion: " << h->header()->version() << "\n";
    os << "\tAcquisition Mode: "
       << ACQUISITION_MODE[h->header()->channel1()->acquisition_mode()] << " ["
       << h->header()->channel1()->acquisition_mode() << "]\n";
    os << "\tTimebase: "
       << format_number(TIMEBASE[h->header()->channel1()->timebase()], "s") << " ["
       << (int)h->header()->channel1()->timebase() << "]\n";
    os << "\tSampling Depth: "
       << format_number(h->header()->channel1()->sampling_depth()) << "\n";
    os << "\tSamples per Second: "
       << format_number(h->header()->channel1()->samples_per_second()) << "\n";
    os << "\tTrigger Type: " << TRIGGER_NAME[h->header()->channel1()->trigger_type()]
       << " [" << h->header()->channel1()->trigger_type() << "]\n";
    os << "\tTrigger Channel: " << h->header()->channel1()->trigger_channel() << "\n";
    os << "\tTrigger Level: " << h->header()->channel1()->trigger_level() << "\n";
    os << "\tHorizontal Offset: " << h->header()->channel1()->horizontal_offset()
       << "\n";
    os << std::flush;
}

void Hantek::print_channel(std::ostream& os, int n, const hantek_t::channel_t* ch)
{
    os << rang::fg::magenta << "Channel " << n << ": " << rang::style::reset << "\n";
    if (ch->enabled()) {
        auto volts_per_div = VOLTS_PER_DIV[ch->volts_per_div()];
        auto volts_per_div_str
            = format_number(volts_per_div * pow(10, ch->mode()), "V");

        os << "\tSample Count: " << format_number(ch->sample_count()) << "\n";
        os << "\tOffset: " << ch->offset() << "\n";
        os << "\tVolts per Division: " << volts_per_div_str << " ["
           << (int)ch->volts_per_div() << "]\n";
        os << "\tProbe Mode: " << pow(10, ch->mode()) << "x [" << (int)ch->mode()
           << "]\n";
    } else {
        os << "\tDisabled\n";
    }
    os << std::flush;
}

double Hantek::timebase()
{
    return 1.0f / h->header()->channel1()->samples_per_second();
}

std::tuple<std::optional<double>, std::optional<double>, std::optional<double>,
    std::optional<double>>
Hantek::next()
{
    auto d1 = h->data1();
    auto d2 = h->data2();
    auto d3 = h->data3();
    auto d4 = h->data4();

    if (idx < d1->size() || idx < d2->size() || idx < d3->size() || idx < d4->size()) {
        auto ch1 = get_data(idx, h->header()->channel1(), h->data1());
        auto ch2 = get_data(idx, h->header()->channel2(), h->data2());
        auto ch3 = get_data(idx, h->header()->channel3(), h->data3());
        auto ch4 = get_data(idx, h->header()->channel4(), h->data4());

        idx++;

        return std::tuple(std::optional(ch1), std::optional(ch2), std::optional(ch3),
            std::optional(ch4));
    } else {
        throw std::runtime_error("Out of data");
    }
}

void Hantek::reset() { idx = 0; }

std::optional<double> Hantek::get_data(
    size_t idx, const hantek_t::channel_t* ch, const std::vector<int16_t>* data)
{
    if (ch->enabled()) {
        // Hantek has 25 ticks per division
        auto volts_per_div = VOLTS_PER_DIV[ch->volts_per_div()] / 25.0f;

        if (idx < data->size()) {
            return std::optional(((*data)[idx] - ch->offset()) * volts_per_div);
        }
    }
    return std::nullopt;
}
