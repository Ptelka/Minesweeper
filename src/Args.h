#ifndef MINESWEEPER_ARGS_H
#define MINESWEEPER_ARGS_H

#include <cstddef>

struct Args {
    Args(int argc, char** argv);

    void usage();

    bool help = false;
    std::size_t xSize = 10;
    std::size_t ySize = 10;
    unsigned minesPercent = 14;
};

#endif //MINESWEEPER_ARGS_H
