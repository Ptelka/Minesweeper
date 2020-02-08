#include "Grid.h"

#include "common/Rect.hpp"

#include <list>
#include <functional>
#include <random>

namespace {

int randomize(int a, int b) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    return std::uniform_int_distribution<int>(a, b)(rng);
}

template <typename Iterator, typename Count>
Iterator advance(Iterator iterator, Count count) {
    std::advance(iterator, count);
    return iterator;
}

}

namespace game {

Grid::Grid(int width, int height, unsigned minesPercentage)
: rect({0, 0, width, height}) {
    createSquares();
    createMines(minesPercentage);
    fillMinesCount();
}

void Grid::createSquares() {
    const auto size = rect.width * rect.height;

    squares.reserve(size);

    for (auto i = 0; i < size; ++i) {
        squares.emplace_back(i % rect.width, i / rect.width);
    }
}

void Grid::createMines(unsigned percentage) {
    std::list<std::reference_wrapper<Square>> list(squares.begin(), squares.end());

    const auto percent = std::min(percentage, 100u) / 100.f;
    mines = static_cast<int>(list.size() * percent);

    for (int i = 0; i < mines; ++i) {
        auto iter = advance(list.begin(), randomize(0, static_cast<int>(list.size()) - 1));

        iter->get().setMine();
        list.erase(iter);
    }
}

void Grid::fillMinesCount() {
    for (auto& square: squares) {
        if (!square.hasMine()) {
            square.setMinesNearby(calculateNearbyMinesCount(square));
        }
    }
}

int Grid::calculateNearbyMinesCount(const Square &square) {
    auto xstart = std::max(square.x - 1, 0);
    auto ystart = std::max(square.y - 1, 0);
    auto xend = std::min(square.x + 1, rect.width - 1);
    auto yend = std::min(square.y + 1, rect.height - 1);

    int result = 0;

    for (auto i = ystart; i <= yend; ++i) {
        for (auto j = xstart; j <= xend; ++j) {
            result += get(j, i).hasMine();
        }
    }

    return result;
}

Square &Grid::get(int x, int y) {
    validate(x, y);
    return squares[y * rect.width + x];
}

const Square &Grid::get(int x, int y) const {
    validate(x, y);
    return squares[y * rect.width + x];
}

void Grid::validate(int x, int y) const {
    if (!rect.check(x, y)) {
        throw std::out_of_range("Out of range (x: " + std::to_string(x) + ", y: " + std::to_string(y) + ")");
    }
}

Squares::const_iterator Grid::begin() const {
    return squares.begin();
}

Squares::const_iterator Grid::end() const {
    return squares.end();
}

int Grid::size() const {
    return squares.size();
}

Squares::iterator Grid::begin() {
    return squares.begin();
}

Squares::iterator Grid::end() {
    return squares.end();
}

int Grid::getMines() const {
    return mines;
}

}
