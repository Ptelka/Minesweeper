#include "game/Minesweeper.h"
#include "Args.h"

#include "game/Grid.h"

#include "view/Initializer.h"
#include "view/Input.h"
#include "view/Cursor.h"
#include "view/Print.h"

namespace symbols {

const char* plain = "[ ]";
const char* revealed = "[_]";
const char* mine = "[*]";
const char* marked = "[\\]";
const char* playing = "(￣_￣) . . .";
const char* won = "\\(￣V￣)/       ";
const char* lost = "(x_x)           ";

}

std::string getSymbol(const game::Square& square) {
    if (square.isRevealed()) {
        if (square.getMinesNearby()) {
            return "[" + std::to_string(square.getMinesNearby()) + "]";
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

void print(const game::Grid& grid) {
    for (const auto& square: grid) {
        auto x = static_cast<int>(square.x);
        auto y = static_cast<int>(square.y);
        view::print(x, y * 3, getSymbol(square));
    }

    auto xOffset = static_cast<int>(grid.rect.width + 2);
    auto yOffset = static_cast<int>(grid.rect.height * 3 + 3);

    view::print(xOffset, 0, symbols::playing);

    view::print(0, yOffset, std::string("plain:    ") + symbols::plain);
    view::print(1, yOffset, std::string("revealed: ") + symbols::revealed);
    view::print(2, yOffset, std::string("mine:     ") + symbols::mine);
    view::print(3, yOffset, std::string("marked:   ") + symbols::marked);

    view::print(5,  yOffset, "up:     w");
    view::print(6,  yOffset, "down:   s");
    view::print(7,  yOffset, "left:   a");
    view::print(8,  yOffset, "right:  d");
    view::print(9,  yOffset, "reveal: space");
    view::print(10, yOffset, "mark:   m");
}

view::Cursor createCursor(const game::Grid& grid) {
    auto rect = grid.rect;
    return {
        static_cast<int>(rect.x),
        static_cast<int>(rect.y),
        {
            static_cast<int>(rect.x),
            static_cast<int>(rect.y),
            static_cast<int>(rect.width),
            static_cast<int>(rect.height)
        }
    };
}

void mark(int x, int y, game::Minesweeper& minesweeper) {
    minesweeper.mark(
        static_cast<std::size_t>(x),
        static_cast<std::size_t>(y)
    );
}

void reveal(int x, int y, game::Minesweeper& minesweeper) {
    minesweeper.reveal(
        static_cast<std::size_t>(x),
        static_cast<std::size_t>(y)
    );
}

void end(bool won, int width) {
    if (won) {
        view::print(width + 2, 0, symbols::won);
    } else {
        view::print(width + 2, 0, symbols::lost);
    }

    while (view::input::get() != view::input::Action::REVEAL) {}
}

int main(int argc, char** argv) {
    Args args(argc, argv);

    if (args.help) {
        args.usage();
        return 0;
    }

    view::Initializer initializer;

    game::Minesweeper minesweeper ({
        args.ySize,
        args.xSize,
        args.minesPercent
    });

    auto cursor = createCursor(minesweeper.getGrid());

    while (!minesweeper.won() && !minesweeper.lost()) {
        print(minesweeper.getGrid());

        cursor.refresh();

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
                mark(cursor.getX(), cursor.getY(), minesweeper);
                break;
            case view::input::Action::REVEAL:
                reveal(cursor.getX(), cursor.getY(), minesweeper);
                break;
            default:
                break;
        }

        initializer.refresh();
    }

    print(minesweeper.getGrid());

    end(minesweeper.won(), static_cast<int>(minesweeper.getGrid().rect.width));

    return 0;
}