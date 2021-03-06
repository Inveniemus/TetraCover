#include <line.h>


std::string tetralib::Line::draw() const {
    std::stringstream txt_stream;

    for (auto cell : cells_) {
        txt_stream << cell.draw();
    }
    txt_stream << "\n";

    return txt_stream.str();
}
