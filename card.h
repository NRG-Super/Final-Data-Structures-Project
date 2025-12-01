//Card.h

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
private:
    std::string rank;
    char suit;
    int value;

public:
    Card(const std::string& r = "?", char s = "?", int v = 0);

    int getValue() const;
    bool isAce() const;
    std::string toString() const;
};


#endif

