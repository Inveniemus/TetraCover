#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <line.h>

#include <cstddef>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class Playfield {
public:
    Playfield(std::size_t width, std::size_t height);
    Playfield() : Playfield(10, 20) {}

    // Debug stuff
    /// to get debugging information
    std::string debug_string() const;

    /// To draw the Playfield to the console
    ///@return std::string 
    ///
    std::string draw() const;

private:
    // As number of cells
    std::size_t width_;
    std::size_t height_;

    std::vector<Line> lines;
};

#endif