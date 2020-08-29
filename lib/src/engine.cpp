#include <engine.h>

#include <algorithm>

tetralib::Engine::Engine() {
    last_snapshot.timer_interval = 1000; // Starts with one second gravity
}

void tetralib::Engine::step() {
    
    if (!active_tetro_) {
        const char new_letter = bag_.get_letter();
        active_tetro_ = std::unique_ptr<Tetromino>(
            new Tetromino(new_letter, playfield_)
        );
        draw_tetro_();
    } else {
        clear_tetro_();
        bool has_dropped = active_tetro_->move_y(-1);
        draw_tetro_();
        if (!has_dropped) freeze_();
    }    
}

void tetralib::Engine::tetro_right() {
    if(move_tetro_(DIRECTION::RIGHT)) notify();
}

void tetralib::Engine::tetro_left() {
    if(move_tetro_(DIRECTION::LEFT)) notify();
}

void tetralib::Engine::tetro_down() {
    if(move_tetro_(DIRECTION::DOWN)) notify();
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
    for (auto observer : observers_) observer->update(last_snapshot);
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

bool tetralib::Engine::move_tetro_(DIRECTION strafe) {
    bool result = false;
    
    clear_tetro_();
    if (active_tetro_) {
        switch (strafe)
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