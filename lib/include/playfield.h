#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <line.h>
#include <cell.h>

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

namespace tetralib {

class Playfield {
public:
    Playfield(std::size_t width, std::size_t height);
    Playfield() : Playfield(10, 22) {}

    ///@brief Getter for any Cell of the Playfield
    ///
    ///@param x column number, starting at 0
    ///@param y line number from bottom to top, starting at 0
    ///@return Cell& a reference to the Cell at (x, y)
    Cell& cell(std::size_t x, std::size_t y);
    const Cell& cell(std::size_t x, std::size_t y) const;

    ///@brief Height of the playfield, as a number of cells
    ///@return size_t number of cells
    size_t height() const { return lines_.size(); }
    
    ///@brief Width of the playfield, as a number of cells
    ///@return size_t number of cells
    size_t width() const { return lines_[0].size(); }

    ///@brief Checks if the cell at x,y is occupied.
    ///@param x position in its line
    ///@param y line position on the playfield
    ///@return true it's occupied!
    ///@return false it's free!
    bool cell_occupied(std::size_t x, std::size_t y) const;

    // Debug stuff
    /// to get debugging information
    std::string debug_string() const;

    /// To draw the Playfield to the console
    ///@return std::string the playfield drawing as a string.
    std::string draw() const;

private:
    // As number of cells
    size_t width_;
    size_t height_;

    std::vector<Line> lines_;
};

} // namespace tetralib

#endif