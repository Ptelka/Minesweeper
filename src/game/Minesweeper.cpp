#include "Minesweeper.h"

namespace game {

Minesweeper::Minesweeper(Grid grid)
: grid(std::move(grid)), mines(grid.getMines()) { }

void Minesweeper::mark(std::size_t x, std::size_t y) {
    auto& square = grid.get(x, y);

    if (square.isMarked()) {
        marked -= square.hasMine();
        square.unmark();
    } else {
        marked += square.hasMine();
        square.mark();
    }

    if (won()) {
        revealAll();
    }
}

void Minesweeper::reveal(std::size_t x, std::size_t y) {
    auto& square = grid.get(x, y);

    if (square.hasMine()) {
        isLost = true;
        revealMines();
    } else if (square.getMinesNearby() == 0) {
        revealNearby(square.x, square.y);
    } else {
        reveal(square);
    }
}

void Minesweeper::reveal(Square &square) {
    if (!square.isRevealed()) {
        ++revealed;
        square.reveal();
    }
}

void Minesweeper::revealAll() {
    for (auto& square: grid) {
        reveal(square);
    }
}

void Minesweeper::revealMines() {
    for (auto& square: grid) {
        if (square.hasMine()) {
            reveal(square);
        }
    }
}

void Minesweeper::revealNearby(std::size_t x, std::size_t y) {
    if (!grid.rect.check(x, y)) {
        return;
    }

    auto& square = grid.get(x, y);

    if (!square.isRevealed()) {
        reveal(square);

        if (square.getMinesNearby() == 0) {
            revealNearby(x - 1, y);
            revealNearby(x + 1, y);
            revealNearby(x, y + 1);
            revealNearby(x, y - 1);
        }
    }
}

bool Minesweeper::won() const {
    return marked == mines && marked + revealed == grid.size();
}

bool Minesweeper::lost() const {
    return isLost;
}

const Grid &Minesweeper::getGrid() const {
    return grid;
}

}