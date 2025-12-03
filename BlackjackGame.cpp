#include "BlackjackGame.h"
#include <iostream>

using namespace std;

void BlackjackGame::playRound() {

    // Prepare game
    deck.reset();
    deck.shuffleDeck();

    player.clear();
    dealer.clear();

    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    player.sortDescending();
    dealer.sortDescending();
    
    cout << "\n===== New Round =====\n";

    cout << "Player Hand: ";
    player.showHand(true);

    cout << "Dealer Hand: "; 
    dealer.showHand(false);

    while (true) {
        if (player.getScore() > 21) {
            cout << "\nPlyaer Busts! Dealer Wins!\n";
            return;
        }

        char choice;
        cout << "\nhit or Stand? (h/s): ";
        cin >> choice;

        if (choice == 's' || choice == 'S') break;

        if (choice == 'h' || choice == 'H') {
            player.addCard(deck.dealCard());
            player.sortDescending();
            cout << "Player Hand: ";
            player.showHand(true);
        } else {
            cout << "Invalid input! Try Again.\n";
        }
    }

    cout << "\nDealer Reveals:\n";
    dealer.sortDescending();
    cout << "Dealer Hand: ";
    dealer.showHand(true);

    while (dealer.getScore() < 17) {
        cout << "Dealer hits...\n";
        dealer.addCard(deck.dealCard());
        dealer.sortDescending();
        cout << "Dealer Hand: ";
        dealer.showHand(true);
    }

    int p = player.getScore();
    int d = dealer.getScore();

    cout << "\n=== Final Results ===\n";
    player.sortDescending();
    dealer.sortDescending();

    cout << "Player: ";
    player.showHand(true);

    cout << "Dealer: ";
    dealer.showHand(true);

    if (d > 21 || p > d) cout << "\nPlayer Wins! \n";
    else if (p == d) cout << "\nIt is a Draw! \n";
    else cout << "\nDealer Wins! \n";
}
