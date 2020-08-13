#include <playfield.h>

Playfield::Playfield(std::size_t width, std::size_t height) :
        width_(width), height_(height) {
    lines.resize(height_);
}

std::string Playfield::debug_string() const {
    std::stringstream txt_stream;

    txt_stream << "PLAYFIELD\nHEIGHT: " << height_ << " WIDTH: " << width_;

    return txt_stream.str();
}

std::string Playfield::draw() const {

    std::stringstream txt_stream;
    // Lines are bottom-up stored. We want to draw reversed order!
    for (auto r_it = lines.rbegin(); r_it != lines.rend(); r_it++) {
        txt_stream << r_it->draw();
    }

    return txt_stream.str();
}