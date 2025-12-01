//BlackjackGame.h

#ifndef BLACKJACKGAME_H
#define BLACKJACKGAME_H

#include "Deck.h"
#include "Hand.h"

class BlackjackGame {
private:
    Deck deck;
    Hand player;
    Hand dealer;
public:
    void playRound();
};

#endif
