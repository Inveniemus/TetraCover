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
    }

    if (!active_tetro_->move_y(-1)) {
        freeze_();
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
    for (auto observer : observers_) observer->update(last_snapshot);
}

// PRIVATE ___________________________________________________________________
void tetralib::Engine::freeze_() {
    active_tetro_.reset(nullptr);
}