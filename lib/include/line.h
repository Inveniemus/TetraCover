#ifndef LINE_H
#define LINE_H

#include <cell.h>

#include <cstddef>
#include <vector>
#include <string>
#include <sstream>

namespace tetralib {

class Line {
public:
    Line() : Line(10) {}
    Line(std::size_t length) { cells_.resize(length); }

    ///@brief get the cell at position x, starting from 0
    ///
    ///@param x cell position in the line
    ///@return Cell& a reference to the Cell
    Cell& cell(size_t x) { return cells_[x]; }
    const Cell& cell(size_t x) const { return cells_[x]; }

    std::size_t size() const { return cells_.size(); }

    // Debug stuff
    std::string draw() const;

private:
    std::vector<Cell> cells_;
};

} // namespace tetralib

#endif