#ifndef HAND_H
#define HAND_H

#include "Card.h"

class Hand {
private:    
    struct Node {
        Card data;
        Node* next;
        Node (const Card& c) : data(c), next(nullptr) {}
    };
    Node* head;

public:
    Hand();
    ~Hand();

    void addCard(const Card& c);
    int getScore() const;
    void clear();
    void sortDescending();
    void showHand(bool showAll) const;
};

#endif
