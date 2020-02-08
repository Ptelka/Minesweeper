#include "Args.h"

#include <string>
#include <getopt.h>
#include <stdexcept>

namespace {

option options[] = {
    {"help", optional_argument, nullptr, 'h'},
    {"xsize", optional_argument, nullptr, 'x'},
    {"ysize", optional_argument, nullptr, 'y'},
    {"mines", optional_argument, nullptr, 'm'},
    {nullptr, 0, nullptr, 0}
};

}

Args::Args(int argc, char **argv) {
    if (argc < 2) {
        return;
    }

    int c;
    int index = 0;

    while ((c = getopt_long(argc, argv, "hx:y:m:", options, &index)) != -1) {
        switch (c) {
            case 'h':
                help = true;
                break;
            case 'x':
                xSize = std::stoul(optarg);
                break;
            case 'y':
                ySize = std::stoul(optarg);
                break;
            case 'm':
                minesPercent = static_cast<unsigned int>(std::stoi(optarg));
                break;
            default:
                break;
        }
    }

    if (xSize < 1) {
        throw std::runtime_error("x cannot be smaller than 1");
    }
    if (ySize < 1) {
        throw std::runtime_error("y cannot be smaller than 1");
    }
    if (minesPercent < 0) {
        throw std::runtime_error("mines percent cannot be smaller than 0");
    }
    if (minesPercent > 100) {
        throw std::runtime_error("mines percent cannot be greater than 100");
    }
}

void Args::usage() {
    printf("--help -h: help\n");
    printf("--mines -m: percentage of mines\n");
    printf("--xsize -x: x size\n");
    printf("--ysize -y: y size\n");
}
