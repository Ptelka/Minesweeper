#ifndef MINESWEEPER_FIELD_H
#define MINESWEEPER_FIELD_H

#include "Square.h"
#include "common/Rect.h"

#include <vector>

namespace game {

using Squares = std::vector<Square>;

class Grid {
public:
    Grid(std::size_t width, std::size_t height, unsigned minesPercentage);

    Square& get(std::size_t x, std::size_t y);
    const Square& get(std::size_t x, std::size_t y) const;

    const Rect<std::size_t> rect;

    Squares::const_iterator begin() const;
    Squares::const_iterator end() const;
    Squares::iterator begin();
    Squares::iterator end();

    std::size_t size() const;
    std::size_t getMines() const;

private:
    void validate(std::size_t x, std::size_t y) const;
    void createSquares();
    void createMines(unsigned percentage);
    void fillMinesCount();

    std::size_t calculateNearbyMinesCount(const Square& square);

    Squares squares;
    std::size_t mines = 0;
};

}

#endif //MINESWEEPER_FIELD_H
