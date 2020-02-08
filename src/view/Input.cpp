#include "Input.h"
#include <ncurses.h>

namespace view {
namespace input {

Action get() {
    auto ch = getch();
    switch (ch) {
        case 'w':
        case KEY_UP:
            return Action::LEFT;
        case 's':
        case KEY_DOWN:
            return Action::RIGHT;
        case 'a':
        case KEY_LEFT:
            return Action::DOWN;
        case 'd':
        case KEY_RIGHT:
            return Action::UP;
        case 'm':
        case 'e':
            return Action::MARK;
        case 32:
        case 10:
            return Action::REVEAL;
        default:
            return Action::UNKNOWN;
    }
}

}
}