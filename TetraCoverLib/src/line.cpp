#include <line.h>

std::string Line::draw() const {
    std::stringstream txt_stream;

    for (auto cell : cells) {
        txt_stream << cell.draw();
    }
    txt_stream << "\n";

    return txt_stream.str();
}