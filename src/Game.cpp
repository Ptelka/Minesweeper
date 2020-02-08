#include "Game.h"

#include "view/Print.h"
#include "view/Input.h"

namespace symbols {

Symbol plain(" ", view::Color::WHITE);
Symbol revealed("_", view::Color::WHITE);
Symbol mine("*", view::Color::RED);
Symbol marked("#", view::Color::BLUE);
const char* playing = "(￣_￣) . . .";
const char* won = "\\(￣V￣)/       ";
const char* lost = "(x_x)           ";

}


Game::Game(const Args &args)
: minesweeper({
    args.ySize,
    args.xSize,
    args.minesPercent
}), cursor(0, 1, minesweeper.getGrid().rect) { }

void Game::start() {
    draw();

    while (!minesweeper.won() && !minesweeper.lost()) {
        input();
        draw();
        view.refresh();
    }

    end();
}

void Game::draw() {
    const auto& grid = minesweeper.getGrid();

    for (const auto& square: grid) {
        getSymbol(square).draw(square.x, square.y * 3);
    }

    auto xOffset = grid.rect.width + 2;
    auto yOffset = grid.rect.height * 3 + 3;

    view::print(xOffset, 0, symbols::playing);

    view::print(0, yOffset, "plain:    " + symbols::plain.str());
    view::print(1, yOffset, "revealed: " + symbols::revealed.str());
    view::print(2, yOffset, "mine:     " + symbols::mine.str());
    view::print(3, yOffset, "marked:   " + symbols::marked.str());

    view::print(5,  yOffset, "up:     w / key up");
    view::print(6,  yOffset, "down:   s / key down");
    view::print(7,  yOffset, "left:   a / key left");
    view::print(8,  yOffset, "right:  d / key right");
    view::print(9,  yOffset, "mark:   m / e");
    view::print(10, yOffset, "reveal: space / return");

    cursor.draw();
}

void Game::input() {
    switch (view::input::get()) {
        case view::input::Action::UP:
            cursor.move(0, 1);
            break;
        case view::input::Action::DOWN:
            cursor.move(0, -1);
            break;
        case view::input::Action::LEFT:
            cursor.move(-1, 0);
            break;
        case view::input::Action::RIGHT:
            cursor.move(1, 0);
            break;
        case view::input::Action::MARK:
            minesweeper.mark(cursor.getX(), cursor.getY() / 3);
            break;
        case view::input::Action::REVEAL:
            minesweeper.reveal(cursor.getX(), cursor.getY() / 3);
            break;
        default:
            break;
    }
}

Symbol Game::getSymbol(const game::Square& square) const {
    if (square.isRevealed()) {
        if (square.getMinesNearby()) {
            return Symbol(square.getMinesNearby(), view::Color::GREEN);
        } else if (square.hasMine()) {
            return symbols::mine;
        } else {
            return symbols::revealed;
        }
    } else if (square.isMarked()) {
        return symbols::marked;
    }

    return symbols::plain;
}

void Game::end() {
    const auto& grid = minesweeper.getGrid();

    if (minesweeper.won()) {
        view::print(grid.rect.width + 2, 0, symbols::won);
    } else {
        view::print(grid.rect.width + 2, 0, symbols::lost);
    }

    while (view::input::get() != view::input::Action::REVEAL) {}
}


