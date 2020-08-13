#ifndef CELL_H
#define CELL_H

#include <color_enum.h>

#include <string>

class Cell {
public:
    Cell() : color(BLACK) {}

    bool is_empty() const { return color == BLACK; }

    std::string draw() const;

private:
    Color color;
};

#endif