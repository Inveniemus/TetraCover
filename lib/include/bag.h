#ifndef BAG_H
#define BAG_H

#include <array>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>
#include <random>

namespace tetralib {

enum Randomizer {
    random_generator_7, // standart random generator
};

static constexpr ::std::array<char, 7> 
        TETROMINOES{'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

class Bag {
public:
    Bag() : randomizer_(random_generator_7) {}

    char get_letter();

private:

    ::std::vector<char> content_;
    Randomizer randomizer_;

    void fill_();
};

} // namespace tetralib

#endif