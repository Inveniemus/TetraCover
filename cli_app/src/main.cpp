#include <playfield.h>
#include <tetromino.h>
#include <engine.h>

#include <iostream>

int main() {

    Playfield playfield;
    auto engine = Engine(playfield);

    engine.step();
    engine.step();

    std::cout << playfield.debug_string() << std::endl;
    std::cout << playfield.draw() << std::endl;

    return 0;
}