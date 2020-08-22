#ifndef BAG_H
#define BAG_H

#include <array>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

enum Randomizer {
    random_generator_7, // standart random generator
};

class Bag {
public:
    Bag() : randomizer_(random_generator_7) {}

    char get_letter();

private:
    static constexpr std::array<char, 7> TETROMINOES{'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

    std::vector<char> content_;
    Randomizer randomizer_;

    void fill_();
};

#endif