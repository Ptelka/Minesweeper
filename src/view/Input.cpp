#include "Input.h"
#include <ncurses.h>
#include <iostream>

namespace view {
namespace input {

Action get() {
    auto ch = getch();
    switch (ch) {
        case 'w':
            return Action::LEFT;
        case 's':
            return Action::RIGHT;
        case 'a':
            return Action::DOWN;
        case 'd':
            return Action::UP;
        case 'm':
            return Action::MARK;
        case ' ':
            return Action::REVEAL;
        default:
            return Action::UNKNOWN;
    }
}

}
}