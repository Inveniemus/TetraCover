#include <bag.h>

constexpr std::array<char, 7> Bag::TETROMINOES;

char Bag::get_letter() {

    if (content_.empty()) {
        fill_();
    }

    char result{content_.back()};
    content_.pop_back();
    return result;
}

// PRIVATE ____________________________________________________________________
void Bag::fill_() {

    content_.clear();
    std::random_device dr;
    std::mt19937 mte(dr());

    switch (randomizer_)
    {
    case random_generator_7:
        std::copy(TETROMINOES.cbegin(), TETROMINOES.cend(),
            std::back_inserter(content_));
        std::shuffle(content_.begin(), content_.end(), mte);
        break;
    
    default:
        break;
    }
}