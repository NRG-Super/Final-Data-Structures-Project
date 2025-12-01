//Hand.h

#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"

class Hand {
private:    
    std::vector<Card> cards;

public:
    void addCard(const Card& c);
    int getScore() const;
    void clear();
    void sortDescending();
    void showHand(bool showAll) const;
};

#endif
