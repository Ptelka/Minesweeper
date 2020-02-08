#ifndef MINESWEEPER_SQUARE_H
#define MINESWEEPER_SQUARE_H

namespace game {

class Square {
public:
    Square(int x, int y);

    void setMine();
    bool hasMine() const;

    void setMinesNearby(int mines);
    int getMinesNearby() const;

    void unmark();
    void mark();
    bool isMarked() const;

    void reveal();
    bool isRevealed() const;

    const int x;
    const int y;

private:
    bool marked = false;
    bool revealed = false;
    bool mine = false;
    int minesNearby = 0;
};

}

#endif //MINESWEEPER_SQUARE_H
