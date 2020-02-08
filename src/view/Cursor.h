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
    void refresh();

private:
    Rect<int> bounds;
    int x, y;
};

}


#endif //MINESWEEPER_CURSOR_H
