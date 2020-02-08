#ifndef MINESWEEPER_SQUARE_H
#define MINESWEEPER_SQUARE_H

#include <cstddef>

namespace game {

class Square {
public:
    Square(std::size_t x, std::size_t y);

    void setMine();
    bool hasMine() const;

    void setMinesNearby(std::size_t mines);
    std::size_t getMinesNearby() const;

    void unmark();
    void mark();
    bool isMarked() const;

    void reveal();
    bool isRevealed() const;

    const std::size_t x;
    const std::size_t y;

private:
    bool marked = false;
    bool revealed = false;
    bool mine = false;
    std::size_t minesNearby = 0;
};

}

#endif //MINESWEEPER_SQUARE_H
