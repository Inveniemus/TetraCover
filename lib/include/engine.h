#ifndef ENGINE_H
#define ENGINE_H

#include <tetromino.h>
#include <bag.h>
#include <playfield.h>
#include <memory>

namespace tetralib {

class Engine {
public:
    ///@brief Construct a new Engine object.
    Engine();

    ///@brief method to call when time elapses between two moves due to 
    /// gravity. It typically moves the active Tetromino down by one increment,
    /// check for collision on the bottom and in such a case freezes the
    /// move and destroy the tetromino. If there is no active Tetromino, it
    /// gets a new one from the bag.
    void step();

    const Playfield& get_playfield() const { return playfield_; }

private:

    Playfield playfield_;
    Bag bag_;

    std::unique_ptr<Tetromino> active_tetro_;
    void freeze_();
};

} // namespace tetralib

#endif