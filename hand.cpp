//Hand.cpp

#include "Hand.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Hand::addCard(const Card& c) {
    cards.push_back(c);
}

int Hand::getScore() const {
    int total = 0;
    int aceCount = 0;

    for (const Card& c : cards) {
        total += c.getValue();
        
        if (c.isAce()) aceCount ++;
    }

    while (total > 21 && aceCount > 0) {
        total -=10;
        aceCount--;
    }
    return;
}

void Hand::clear() {
    cards.clear();
}

void Hand::sortDescending() {
    sort(cards.begin(), cards.end(), [](const Card& a, const Card& b) {
        return a.getValue() > b.getValue();
    });
}

void Hand::showHand(bool showAll) const {
    for (size_t i = 0; i < cards.size(); i++) {
        if (!showAll && i == 1) 
            cout << "[ ? ] ";
        else 
        cout << "[" << cards[i].toString() << "] ";
    }

    if (showAll)
        cout << "(Score : " << getScore() << ")";
    
    cout << endl;
}


