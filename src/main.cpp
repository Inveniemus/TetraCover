#include <playfield.h>

#include <iostream>

int main() {

    Playfield playfield;
    std::cout << playfield.debug_string() << std::endl;
    std::cout << playfield.draw() << std::endl;

    return 1;
}