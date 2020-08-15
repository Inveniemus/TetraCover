#include <playfield.h>
#include <tetromino.h>

#include <iostream>

int main() {

    Playfield playfield;
    auto tetro_I = Tetromino {'I', playfield};
    tetro_I.move_x(1);

    std::cout << playfield.debug_string() << std::endl;
    std::cout << playfield.draw() << std::endl;

    return 1;
}