#include "Card.h"

Card::Card() {}

Card::Card(int rank, Color color) {
    this->rank = rank;
    this->color = color;
    if (color == purple) {
        this->value = rank;
    }
    else if (color == orange) {
        this->value = rank * 2;
    }
}

std::string Card::printCard() {
    std::string color_str;
    if (color == purple) {
        color_str = "purple";
    }
    else if (color == orange) {
        color_str = "orange";
    }
    return color_str + ":" + std::to_string(rank);
}

int Card::getRank() {
    return rank;
}

Card::Color Card::getColor() {
    return color;
}

int Card::getValue() {
    return value;
}
