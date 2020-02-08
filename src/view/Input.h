#ifndef MINESWEEPER_INPUT_H
#define MINESWEEPER_INPUT_H

namespace view {
namespace input {

enum class Action {
    UP,
    DOWN,
    RIGHT,
    LEFT,
    MARK,
    REVEAL,
    UNKNOWN
};

Action get();

}
}

#endif //MINESWEEPER_INPUT_H
