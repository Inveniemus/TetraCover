#ifndef ENGINE_H
#define ENGINE_H

#include <tetromino.h>
#include <bag.h>
#include <playfield.h>
#include <observer.h>

#include <memory>
#include <functional>

namespace tetralib {

class Engine : public Observable {
public:
    ///@brief Construct a new Engine object.
    Engine();

    ///@brief method to call when time elapses between two moves due to 
    /// gravity. It typically moves the active Tetromino down by one increment,
    /// check for collision on the bottom and in such a case freezes the
    /// move and destroy the tetromino. If there is no active Tetromino, it
    /// gets a new one from the bag.
    void step();

    void strafe_left() { active_tetro_->move_x(-1); }
    void strafe_right() { active_tetro_->move_x(1); }

    const Playfield& get_playfield() const { return playfield_; }
    void change_timer_interval(size_t new_interval) {
        last_snapshot.timer_interval = new_interval;
        notify();
    }

    // Observable implementation
    void add_observer(Observer*);
    void remove_observer(Observer*);
    void notify();

private:

    Playfield playfield_;
    Bag bag_;

    std::unique_ptr<Tetromino> active_tetro_;
    void freeze_();

    std::vector<Observer*> observers_;
    EngineSnapshot last_snapshot;
};

} // namespace tetralib

#endif