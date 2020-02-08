#ifndef MINESWEEPER_COLORS_H
#define MINESWEEPER_COLORS_H

#include <unordered_map>

namespace view {

enum Color : uint8_t {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

class Colors {
public:
    static int get(Color a, Color b);
};

}


#endif //MINESWEEPER_COLORS_H
