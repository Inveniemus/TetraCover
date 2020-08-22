#ifndef COORDS_H
#define COORDS_H

#include <cstddef>
#include <utility>

///@brief Simple handling class for coordinates
class Coords {
public:
    Coords(std::size_t x, std::size_t y) : x_(x), y_(y) {}
    
    std::size_t x() const { return x_; }
    std::size_t y() const { return y_; }

    void set_x(std::size_t x) { x_ = x; }
    void set_y(std::size_t y) { y_ = y; }

private:
    std::size_t x_;
    std::size_t y_;
};

#endif