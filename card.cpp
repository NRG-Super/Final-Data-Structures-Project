//Card.cpp

#include "Card.h"

Card::Card(const std::string& r, char s, int v) : rank(r), suit(s), value(v) {}

int Card::getValue() const {
    return value;
}

bool Card::isAce() const {
    return rank == "A";
}

std::string Card::toString() const {
    return rank + "-" + suit;
}
