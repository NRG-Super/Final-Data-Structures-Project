//main.cpp

#include <iostream>
#include "BlackjackGame.h"

using namespace std;

int main () {
    BlackjackGame game;
    char again;

    cout << "==== Blackjack Game ====\n";

    do {
        game.playRound();
        cout << "\nPlay again? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "\nThanks for playing! \n";
    return 0;
}
