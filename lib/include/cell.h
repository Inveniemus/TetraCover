#ifndef CELL_H
#define CELL_H

#include <color_enum.h>

#include <string>

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

#endif