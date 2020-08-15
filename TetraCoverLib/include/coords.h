#ifndef COORDS_H
#define COORDS_H

#include <cstddef>
#include <utility>

///@brief Simple handling class for coordinates
class Coords {
public:
    Coords(std::size_t x, std::size_t y) { coords_ = std::make_pair(x, y); }
    
    std::size_t x() const { return coords_.first; }
    std::size_t y() const { return coords_.second; }

    void set_x(std::size_t x) { coords_.first = x; }
    void set_y(std::size_t y) { coords_.first = y; }

private:
    std::pair<std::size_t, std::size_t> coords_;
};

#endif