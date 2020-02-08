#include "View.h"
#include <ncurses.h>

view::View::View() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
    }
}

view::View::~View() {
    endwin();
}

void view::View::refresh() {
    ::refresh();
}
