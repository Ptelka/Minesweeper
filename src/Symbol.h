#ifndef MINESWEEPER_SYMBOL_H
#define MINESWEEPER_SYMBOL_H

#include "view/Colors.h"

#include <string>

class Symbol {
public:
    Symbol(const std::string& symbol, view::Color color, view::Color frameColor = view::WHITE) noexcept;
    Symbol(int number, view::Color color, view::Color frameColor = view::WHITE) noexcept;

    void draw(int x, int y);

    std::string str();

private:
    std::string symbol;

    view::Color color;
    view::Color frameColor;
};


#endif //MINESWEEPER_SYMBOL_H
