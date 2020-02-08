#ifndef MINESWEEPER_RECT_H
#define MINESWEEPER_RECT_H

template <typename T>
struct Rect {
    bool check(T x, T y) const;

    T x;
    T y;
    T width;
    T height;
};


#endif //MINESWEEPER_RECT_H
