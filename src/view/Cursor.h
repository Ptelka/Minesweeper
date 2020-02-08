#ifndef MINESWEEPER_CURSOR_H
#define MINESWEEPER_CURSOR_H

#include "common/Rect.h"

namespace view {

class Cursor {
public:
    Cursor(int x, int y, Rect<int> bounds);

    int getX() const;
    int getY() const;

    void move(int x, int y);
    void draw();

private:
    int x, y;
    Rect<int> bounds;
};

}


#endif //MINESWEEPER_CURSOR_H
