#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Args.h"

#include "Symbol.h"

#include "game/Minesweeper.h"
#include "view/Cursor.h"
#include "view/View.h"


class Game {
public:
    explicit Game(const Args& args);

    void start();

private:
    game::Minesweeper minesweeper;
    view::View view;
    view::Cursor cursor;

    void input();
    void draw();
    void end();

    Symbol getSymbol(const game::Square& square) const;
};


#endif //MINESWEEPER_GAME_H
