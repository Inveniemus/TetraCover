#include <playfield.h>
#include <tetromino.h>

#include <iostream>

int main() {

    Playfield playfield;
    auto tetro_I = Tetromino {'I', playfield};

    while(tetro_I.move_x(1)) {
        std::cout << playfield.draw() << std::endl;
    }
    
    while(tetro_I.move_x(-1)) {
        std::cout << playfield.draw() << std::endl;
    }

    while(tetro_I.move_y(-1)) {
        std::cout << playfield.draw() << std::endl;
    }

    auto tetro_T = Tetromino {'T', playfield};

    while(tetro_T.move_x(1)) {
        std::cout << playfield.draw() << std::endl;
    }
    
    while(tetro_T.move_x(-1)) {
        std::cout << playfield.draw() << std::endl;
    }

    while(tetro_T.move_y(-1)) {
        std::cout << playfield.draw() << std::endl;
    }

    std::cout << playfield.debug_string() << std::endl;
    std::cout << playfield.draw() << std::endl;

    return 0;
}