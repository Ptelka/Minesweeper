#include "Grid.h"

#include "common/Rect.hpp"

#include <list>
#include <functional>
#include <random>

namespace {

std::size_t randomize(std::size_t a, std::size_t b) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    return std::uniform_int_distribution<std::size_t>(a, b)(rng);
}

template <typename Iterator, typename Count>
Iterator advance(Iterator iterator, Count count) {
    std::advance(iterator, count);
    return iterator;
}

}

namespace game {

Grid::Grid(std::size_t width, std::size_t height, unsigned minesPercentage)
: rect({0, 0, width, height}) {
    createSquares();
    createMines(minesPercentage);
    fillMinesCount();
}

void Grid::createSquares() {
    const auto size = rect.width * rect.height;

    squares.reserve(size);

    for (auto i = 0ul; i < size; ++i) {
        squares.emplace_back(i % rect.width, i / rect.width);
    }
}

void Grid::createMines(unsigned percentage) {
    std::list<std::reference_wrapper<Square>> list(squares.begin(), squares.end());

    const auto percent = std::min(percentage, 100u) / 100.f;
    mines = static_cast<std::size_t>(list.size() * percent);

    for (std::size_t i = 0ul; i < mines; ++i) {
        auto iter = advance(list.begin(), randomize(0, list.size() - 1));

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

std::size_t Grid::calculateNearbyMinesCount(const Square &square) {
    auto xstart = static_cast<std::size_t>(std::max(static_cast<int>(square.x - 1), 0));
    auto ystart = static_cast<std::size_t>(std::max(static_cast<int>(square.y - 1), 0));
    auto xend = std::min(square.x + 1, rect.width - 1);
    auto yend = std::min(square.y + 1, rect.height - 1);

    std::size_t result = 0;

    for (auto i = ystart; i <= yend; ++i) {
        for (auto j = xstart; j <= xend; ++j) {
            result += get(j, i).hasMine();
        }
    }

    return result;
}

Square &Grid::get(std::size_t x, std::size_t y) {
    validate(x, y);
    return squares[y * rect.width + x];
}

const Square &Grid::get(std::size_t x, std::size_t y) const {
    validate(x, y);
    return squares[y * rect.width + x];
}

void Grid::validate(std::size_t x, std::size_t y) const {
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

std::size_t Grid::size() const {
    return squares.size();
}

Squares::iterator Grid::begin() {
    return squares.begin();
}

Squares::iterator Grid::end() {
    return squares.end();
}

std::size_t Grid::getMines() const {
    return mines;
}

}
