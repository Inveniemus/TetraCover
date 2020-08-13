#include <cell.h>

std::string Cell::draw() const {
    switch (color)
    {
    case BLACK:
        return "B";
        break;

    case LIGHT_BLUE:
        return "I";
        break;
    
    case YELLOW:
        return "O";
        break;

    case PURPLE:
        return "T";
        break;

    case GREEN:
        return "S";
        break;

    case RED:
        return "Z";
        break;

    case BLUE:
        return "J";
        break;

    case ORANGE:
        return "L";
        break;
    
    // unreachable - to avoid warning
    default:
        return "X";
        break;
    }
}