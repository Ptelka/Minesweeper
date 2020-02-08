#ifndef MINESWEEPER_FIELD_H
#define MINESWEEPER_FIELD_H

#include "Square.h"
#include "common/Rect.h"

#include <vector>

namespace game {

using Squares = std::vector<Square>;

class Grid {
public:
    Grid(int width, int height, unsigned minesPercentage);

    Square& get(int x, int y);
    const Square& get(int x, int y) const;

    const Rect<int> rect;

    Squares::const_iterator begin() const;
    Squares::const_iterator end() const;
    Squares::iterator begin();
    Squares::iterator end();

    int size() const;
    int getMines() const;

private:
    void validate(int x, int y) const;
    void createSquares();
    void createMines(unsigned percentage);
    void fillMinesCount();

    int calculateNearbyMinesCount(const Square& square);

    Squares squares;
    int mines = 0;
};

}

#endif //MINESWEEPER_FIELD_H
