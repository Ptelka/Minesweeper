cmake_minimum_required(VERSION 3.1)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(SOURCE_FILES
        src/game/Grid.cpp
        src/game/Square.cpp
        src/game/Minesweeper.cpp

        src/view/Initializer.cpp
        src/view/Input.cpp
        src/view/Cursor.cpp
        src/view/Print.cpp

        src/Args.cpp
)

add_executable(Minesweeper src/main.cpp ${SOURCE_FILES})
target_link_libraries(Minesweeper -lncurses)