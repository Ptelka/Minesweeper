#ifndef MINESWEEPER_MINESWEEPER_H
#define MINESWEEPER_MINESWEEPER_H

#include "Grid.h"

namespace game {

class Minesweeper {
public:
    explicit Minesweeper(Grid grid);

    void mark(int x, int y);
    void reveal(int x, int y);

    const Grid& getGrid() const;

    bool won() const;
    bool lost() const;
    int marks() const;

private:
    void reveal(Square& square);
    void revealAll();
    void revealMines();
    void revealNearby(int x, int y);

    Grid grid;

    bool isLost = false;
    int marked = 0;
    int mines = 0;
    int revealed = 0;
};

}


#endif //MINESWEEPER_MINESWEEPER_H
