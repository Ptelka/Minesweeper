#ifndef MINESWEEPER_PRINT_H
#define MINESWEEPER_PRINT_H

#include "Colors.h"
#include <string>

namespace view {

void print(int x, int y, const std::string& data);
void print(int x, int y, const std::string& data, Color fg, Color bg = Color::BLACK);

}



#endif //MINESWEEPER_PRINT_H
