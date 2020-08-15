#include <playfield.h>

Playfield::Playfield(std::size_t width, std::size_t height) :
        width_(width), height_(height) {
    lines_.resize(height_);
}

Cell& Playfield::cell(std::size_t x, std::size_t y) {
    if (!(x < width_) && (y < height_)) {
        std::cout << x << " - " << y << std::endl;
        throw std::out_of_range(std::string("Trying to access a cell."));
    }

    return lines_[y].cell(x);
}

std::string Playfield::debug_string() const {
    std::stringstream txt_stream;

    txt_stream << "PLAYFIELD\nHEIGHT: " << height_ << " WIDTH: " << width_;

    return txt_stream.str();
}

std::string Playfield::draw() const {

    std::stringstream txt_stream;
    
    // Lines are bottom-up stored. We want to draw reversed order!
    for (auto r_it = lines_.rbegin(); r_it != lines_.rend(); r_it++) {
        txt_stream << r_it->draw();
    }

    return txt_stream.str();
}