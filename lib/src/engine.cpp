#include <engine.h>

void Engine::step() {
    
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

void Engine::freeze_() {
    active_tetro_.reset(nullptr);
}