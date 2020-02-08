#ifndef MINESWEEPER_RECT_HPP
#define MINESWEEPER_RECT_HPP

#include "Rect.h"

template<typename T>
bool Rect<T>::check(T x, T y) const {
    return x >= this->x &&
           y >= this->y &&
           x < this->x + width &&
           y < this->y + height;
}

#endif //MINESWEEPER_RECT_HPP