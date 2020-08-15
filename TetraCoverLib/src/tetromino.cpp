#include <tetromino.h>

Tetromino::Tetromino(char nature, Playfield& playfield) :
         playfield_(playfield) {
    
    // Index of the central cell or the one immediately to the left if even
    auto reference_index = (playfield.width() - 1) / 2;
    auto height = playfield.height();
    
    // I, O, T, S, Z, J or L
    switch (nature)
    {
    case 'I':
        color_ = LIGHT_BLUE;
        // y is height - 1 because the spawn is on the top of the spawning area
        cell_coords_.push_back(Coords(reference_index - 1, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 1));
        cell_coords_.push_back(Coords(reference_index + 1, height - 1));
        cell_coords_.push_back(Coords(reference_index + 2, height - 1));
        break;

    case 'O':
        color_ = YELLOW;
        cell_coords_.push_back(Coords(reference_index, height - 1));
        cell_coords_.push_back(Coords(reference_index + 1, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 2));
        cell_coords_.push_back(Coords(reference_index + 1, height - 2));
        break;

    case 'T':
        color_ = PURPLE;
        cell_coords_.push_back(Coords(reference_index, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 2));
        cell_coords_.push_back(Coords(reference_index - 1, height - 2));
        cell_coords_.push_back(Coords(reference_index + 1, height - 2));
        break;

    case 'S':
        color_ = GREEN;
        cell_coords_.push_back(Coords(reference_index, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 2));
        cell_coords_.push_back(Coords(reference_index - 1, height - 2));
        cell_coords_.push_back(Coords(reference_index + 1, height - 1));
        break;

    case 'Z':
        color_ = RED;
        cell_coords_.push_back(Coords(reference_index, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 2));
        cell_coords_.push_back(Coords(reference_index - 1, height - 1));
        cell_coords_.push_back(Coords(reference_index + 1, height - 2));
        break;

    case 'J':
        color_ = BLUE;
        cell_coords_.push_back(Coords(reference_index - 1, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 2));
        cell_coords_.push_back(Coords(reference_index - 1, height - 2));
        cell_coords_.push_back(Coords(reference_index + 1, height - 2));
        break;

    case 'L':
        color_ = ORANGE;
        cell_coords_.push_back(Coords(reference_index + 1, height - 1));
        cell_coords_.push_back(Coords(reference_index, height - 2));
        cell_coords_.push_back(Coords(reference_index - 1, height - 2));
        cell_coords_.push_back(Coords(reference_index + 1, height - 2));
        break;
    
    default:
        break;
    }

    update_playfield_();
}

bool Tetromino::move_x(short dx) {

    for (const auto& cell_c : cell_coords_) {
        // Left and right walls collision
        if ((short)cell_c.x() + dx < 0) return false;
        if ((short)cell_c.x() + dx >= playfield_.width()) return false;
    }

    clear_playfield_();
    for (auto& cell_c : cell_coords_) {
        cell_c.set_x(cell_c.x() + dx);
    }
    update_playfield_();
    
    return true;
}

bool Tetromino::move_y(short dy) {

    for (const auto& cell_c : cell_coords_) {
        // Bottom and top(?!?) walls collision
        if ((short)cell_c.y() + dy < 0) return false;
        if ((short)cell_c.y() + dy >= playfield_.height()) return false;
    }

    clear_playfield_();
    for (auto& cell_c : cell_coords_) {
        cell_c.set_y(cell_c.y() + dy);
    }
    update_playfield_();
    
    return true;
}

// PRIVATE_____________________________________________________________________

void Tetromino::update_playfield_() const {
    for (const auto cell_coord : cell_coords_) {
        playfield_.cell(cell_coord.x(), cell_coord.y()).set_color(color_);
    }
}

void Tetromino::clear_playfield_() const {
    for (const auto cell_coord : cell_coords_) {
        playfield_.cell(cell_coord.x(), cell_coord.y()).set_color(BLACK);
    }
}
