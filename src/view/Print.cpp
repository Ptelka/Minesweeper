#include "Print.h"
#include <ncurses.h>

namespace view {

void print(int x, int y, const std::string& data) {
    mvprintw(x, y, data.c_str());
}

}