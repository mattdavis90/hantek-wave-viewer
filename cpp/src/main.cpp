#include "hantek.hpp"
#include "vcd.hpp"
#include "version.hpp"

#include <argparse/argparse.hpp>
#include <rang.hpp>

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("hantek", VERSION);

    argparse::ArgumentParser info("info");
    info.add_description("Show information about the lwf");
    info.add_argument("filename").help("LWF file to process");
    program.add_subparser(info);

    argparse::ArgumentParser vcd("vcd");
    vcd.add_description("Generate a VCD file");
    vcd.add_argument("filename").help("LWF file to process");
    vcd.add_argument("output").help("VCD to generate");
    program.add_subparser(vcd);

    try {
        program.parse_args(argc, argv);
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return 1;
    }

    std::cout << rang::fg::green << "Hantek Wave Viewer v" << VERSION << "\n"
              << rang::style::reset << std::endl;

    try {
        if (program.is_subcommand_used("info")) {
            auto filename = info.get<std::string>("filename");
            Hantek hantek(filename);
            hantek.print();
        } else if (program.is_subcommand_used("vcd")) {
            auto filename = vcd.get<std::string>("filename");
            auto output   = vcd.get<std::string>("output");

            Hantek hantek(filename);

            VCD vcd(output, hantek.timebase());

            while (true) {
                try {
                    auto data = hantek.next();
                    vcd.dump(std::get<0>(data), std::get<1>(data), std::get<2>(data),
                        std::get<3>(data));
                } catch (std::runtime_error e) {
                    break;
                }
            }
        } else {
            std::cout << program << std::endl;
        }
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
