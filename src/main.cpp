#include "Game.h"

int main(int argc, char** argv) {
    Args args(argc, argv);

    if (args.help) {
        args.usage();
        return 0;
    }

    Game(args).start();

    return 0;
}