cmake_minimum_required(VERSION 3.17)

project(TetraCoverLib)

if (MSCV)
    message("Using msvc compiler...")
else()
    message("Using GCC compiler")
    add_compile_options(-Wall -Wextra -Wswitch-enum)
endif()

add_library(TetraCoverLib STATIC 
    src/playfield.cpp
    src/line.cpp
    src/cell.cpp
    src/tetromino.cpp
    src/bag.cpp
    src/engine.cpp
)

target_include_directories(TetraCoverLib PUBLIC include)
