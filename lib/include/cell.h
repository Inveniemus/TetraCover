#ifndef CELL_H
#define CELL_H

#include <string>

#include <color_enum.h>

namespace tetralib {

class Cell {
public:
    Cell() : color_(BLACK) {}

    bool is_empty() const { return color_ == BLACK; }

    void set_color(const Color color) { color_ = color; }
    const Color& color() const { return color_; }

    std::string draw() const;

private:
    Color color_;
};

} // namespace tetralib

#endif