#include <playfield.h>
#include <tetromino.h>
#include <engine.h>

#include <iostream>

int main() {

    using tetralib::Playfield;
    using tetralib::Engine;

    auto engine = Engine();
    auto const playfield = engine.get_playfield();

    engine.step();
    engine.step();

    std::cout << playfield.debug_string() << std::endl;
    std::cout << playfield.draw() << std::endl;

    return 0;
}