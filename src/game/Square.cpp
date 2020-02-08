#include "Square.h"

namespace game {

Square::Square(int x, int y)
: x(x), y(y) { }

void Square::setMine() {
    mine = true;
}

bool Square::hasMine() const {
    return mine;
}

void Square::setMinesNearby(int mines) {
    minesNearby = mines;
}

int Square::getMinesNearby() const {
    return minesNearby;
}

bool Square::isMarked() const {
    return marked;
}

void Square::mark() {
    marked = true;
}

void Square::reveal() {
    revealed = true;
}

bool Square::isRevealed() const {
    return revealed;
}

void Square::unmark() {
    marked = false;
}

}