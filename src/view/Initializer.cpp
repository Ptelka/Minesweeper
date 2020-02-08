#include "Initializer.h"
#include <ncurses.h>

view::Initializer::Initializer() {
    initscr();
}

view::Initializer::~Initializer() {
    endwin();
}

void view::Initializer::refresh() {
    ::refresh();
}
