#include <engine.h>

#include <algorithm>

tetralib::Engine::Engine() {
    current_snapshot.timer_interval = 1000; // Starts with one second gravity
}

void tetralib::Engine::step() {
    
    std::cout << "STEP" << std::endl;
    
    if (!active_tetro_) {
        const char new_letter = bag_.get_letter();
        active_tetro_ = std::unique_ptr<Tetromino>(
            new Tetromino(new_letter, playfield_)
        );
        draw_tetro_();
    } else {
        if (!move_tetro_(DIRECTION::DOWN))
            freeze_();
    }
    current_snapshot.playfield_changed = true;
    notify();
}

void tetralib::Engine::tetro_right() {
    if(move_tetro_(DIRECTION::RIGHT)) {
        current_snapshot.playfield_changed = true;
        notify();
    }
}

void tetralib::Engine::tetro_left() {
    if(move_tetro_(DIRECTION::LEFT)) {
        current_snapshot.playfield_changed = true;
        notify();
    }
}

void tetralib::Engine::tetro_down() {
    if(move_tetro_(DIRECTION::DOWN)) {
        current_snapshot.playfield_changed = true;
        notify();
    }
}

// Observable implementation
void tetralib::Engine::add_observer(Observer* observer) {
    observers_.push_back(observer);
    notify();
}

void tetralib::Engine::remove_observer(Observer* observer) {
    std::remove(observers_.begin(), observers_.end(), observer);
}

void tetralib::Engine::notify() {
    std::cout << current_snapshot.timer_interval << std::endl;
    std::cout << (current_snapshot.playfield_changed ? "CHANGED" : "UNCHANGED") << std::endl;
    for (auto observer : observers_) observer->update(current_snapshot);
    current_snapshot.reset();
}

// PRIVATE ___________________________________________________________________
void tetralib::Engine::draw_tetro_() {
    for (const auto cell_coord : active_tetro_->get_cell_coords()) {
        playfield_.cell(cell_coord.x(), cell_coord.y())
            .set_color(active_tetro_->get_color());
    }
}

void tetralib::Engine::clear_tetro_() {
    for (const auto cell_coord : active_tetro_->get_cell_coords()) {
        playfield_.cell(cell_coord.x(), cell_coord.y()).set_color(BLACK);
    }
}

void tetralib::Engine::freeze_() {
    active_tetro_.reset(nullptr);
}

bool tetralib::Engine::move_tetro_(DIRECTION direction) {
    bool result = false;
    
    clear_tetro_();
    if (active_tetro_) {
        switch (direction)
        {
        case DIRECTION::RIGHT:
            result = active_tetro_->move_x(1);
            break;
        case DIRECTION::LEFT:
            result = active_tetro_->move_x(-1);
            break;
        case DIRECTION::DOWN:
            result = active_tetro_->move_y(-1);
            break;
        }
    }
    draw_tetro_();
    return result;
}