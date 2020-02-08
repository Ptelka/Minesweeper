#include "Cursor.h"
#include "common/Rect.hpp"

#include <ncurses.h>

namespace view {

Cursor::Cursor(int x, int y, Rect<int> bounds)
: x(x), y(y), bounds(bounds) {
    refresh();
}

int Cursor::getX() const {
    return x;
}

int Cursor::getY() const {
    return y;
}

void Cursor::move(int x, int y) {
    auto newX = this->x + x;
    auto newY = this->y + y;

    if (bounds.check(newX, newY)) {
        this->x = newX;
        this->y = newY;
    }
}

void Cursor::draw() {
    ::move(this->x, this->y * 3 + 1);
}

}