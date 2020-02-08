#include "Print.h"
#include <ncurses.h>

namespace view {

void print(int x, int y, const std::string& data) {
    mvprintw(x, y, data.c_str());
}

void print(int x, int y, const std::string& data, Color fg, Color bg) {
    attron(COLOR_PAIR(Colors::get(fg, bg)));
    mvprintw(x, y, data.c_str());
    attroff(COLOR_PAIR(Colors::get(fg, bg)));
}

}