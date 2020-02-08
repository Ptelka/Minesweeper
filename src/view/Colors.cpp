#include "Colors.h"
#include <ncurses.h>

namespace {
short getColorId(view::Color c) {
    switch (c) {
        case view::BLACK:
            return COLOR_BLACK;
        case view::RED:
            return COLOR_RED;
        case view::GREEN:
            return COLOR_GREEN;
        case view::YELLOW:
            return COLOR_YELLOW;
        case view::BLUE:
            return COLOR_BLUE;
        case view::MAGENTA:
            return COLOR_MAGENTA;
        case view::CYAN:
            return COLOR_CYAN;
        case view::WHITE:
            return COLOR_WHITE;
    }

    throw std::runtime_error("Unknown color: " + std::to_string(c));
}
}

int view::Colors::get(view::Color a, view::Color b) {
    static std::unordered_map<uint8_t, int> pairs;
    static short counter = 1;

    uint8_t key = a | (b << 4u);
    auto pair = pairs.find(key);

    if (pair == pairs.end()) {
        auto id = counter++;
        init_pair(id, getColorId(a), getColorId(b));
        pair = pairs.insert({key, id}).first;
    }

    return pair->second;
}
