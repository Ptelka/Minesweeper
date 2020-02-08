#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include "Grid.h"

namespace game {

class Minesweeper {
public:
    explicit Minesweeper(Grid grid);

    void mark(std::size_t x, std::size_t y);
    void reveal(std::size_t x, std::size_t y);

    const Grid& getGrid() const;

    bool won() const;
    bool lost() const;

private:
    void reveal(Square& square);
    void revealAll();
    void revealMines();
    void revealNearby(std::size_t x, std::size_t y);

    Grid grid;

    bool isLost = false;
    std::size_t marked = 0;
    std::size_t mines = 0;
    std::size_t revealed = 0;
};

}


#endif //MINESWEEPER_MINESWEEPER_H
