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

        const int new_x = cell_c.x() + dx;
        const int y = cell_c.y();

        // Left and right walls collision
        if (new_x < 0) return false;
        if (new_x >= (int)playfield_.width()) return false;

        // Left and right occupied cell collision, IF NOT part of this 
        // Tetromino.
        if (!contains_cell_(new_x, y) && 
                playfield_.cell_occupied(new_x, y)) 
            return false;
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

        const int x = cell_c.x();
        const int new_y = cell_c.y() + dy;
        

        // Left and right walls collision
        if (new_y < 0) return false;
        if (new_y >= (int)playfield_.height()) return false;

        // Left and right occupied cell collision, IF NOT part of this 
        // Tetromino.
        if (!contains_cell_(x, new_y) && 
                playfield_.cell_occupied(x, new_y)) 
            return false;
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

bool Tetromino::contains_cell_(std::size_t x, std::size_t y) const {
    return std::any_of(
        cell_coords_.cbegin(),
        cell_coords_.cend(),
        [x, y](Coords coords) {
            return coords.x() == x && coords.y() == y;
        }
    );
}
