#include "Symbol.h"

#include "view/Print.h"


Symbol::Symbol(const std::string& symbol, view::Color color, view::Color frameColor) noexcept
: symbol(symbol), color(color), frameColor(frameColor) { }

void Symbol::draw(int x, int y) {
    view::print(x, y, "[", frameColor);
    view::print(x, y + 1, symbol, color);
    view::print(x, y + 2, "]", frameColor);
}

Symbol::Symbol(int number, view::Color color, view::Color frameColor) noexcept
: symbol(std::to_string(number)), color(color), frameColor(frameColor) { }

std::string Symbol::str() {
    return "[" + symbol + "]";
}
