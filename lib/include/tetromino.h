#ifndef TETROMINO_H
#define TETROMINO_H

#include <cell.h>
#include <playfield.h>
#include <color_enum.h>
#include <coords.h>

#include <vector>
#include <algorithm>

namespace tetralib {

///@brief Defines a Tetromino, imcluding:
/// - Which cells it occupies,
/// - How it move right, left, and how it rotates
/// - Its lifecycle.
class Tetromino {
public:

    ///@brief Construct a new Tetromino object from its nature.
    /// It can be I, O, T, S, Z, J or L
    ///@param nature a char as nature.
    Tetromino(char nature, Playfield& playfield);

    ///@brief Moves a tetromino horizontally and returns true if the move is
    /// possible. Otherwise, there is no move and it returns false.
    ///@param dx 
    ///@return true when the move is possible and was done.
    ///@return false when the move is impossible.
    bool move_x(short dx);

    ///@brief Moves a tetromino vertically and returns true if the move is
    /// possible. Otherwise, there is no move and it returns false.
    ///@param dy
    ///@return true when the move is possible and was done.
    ///@return false when the move is impossible.
    bool move_y(short dy);

private:
    Color color_;
    std::vector<Coords> cell_coords_;

    Playfield& playfield_;
    void update_playfield_() const;
    void clear_playfield_() const;

    bool contains_cell_(std::size_t x, std::size_t y) const;
};

} // namespace tetralib

#endif