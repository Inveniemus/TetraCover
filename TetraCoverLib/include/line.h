#ifndef LINE_H
#define LINE_H

#include <cell.h>

#include <cstddef>
#include <vector>
#include <string>
#include <sstream>

class Line {
public:
    Line() : Line(10) {}
    Line(std::size_t length) : length_(length) { cells.resize(length); }

    // Debug stuff
    std::string draw() const;

private:
    std::size_t length_;

    std::vector<Cell> cells;
};

#endif