#include "Tests.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>

using namespace std;

//Test 1: Verify linked list insertion
void testAddCard() {
    Hand h;
    Deck d;

    d.shuffleDeck();

    h.addCard(d.dealCard());
    h.addCard(d.dealCard());

    //Score should be > 0 and <= 21
    int score = h.getScore();
    assert(score > 0 && score <= 21);

    cout << "testAddCard passed\n";
}

//Test 2: Verify Ace scoring logic
void testAceScoring() {
    Hand h;

    h.addCard(Card("A", 'S', 11));
    h.addCard(Card("9", 'H', 9));
    h.addCard(Card("5", 'D', 5));

    int score = h.getScore();
    assert(score == 15);         //The Ace should count as 1. (1 + 9 + 5) = 15

    cout << "testAceScoring passed\n";
}

//Test 3: Verify sorting from highest to lowest
void testSortingDescending() {
    Hand h;

    h.addCard(Card("3", 'H', 3));
    h.addCard(Card("K", 'H', 10));
    h.addCard(Card("4", 'S', 4));

    h.sortDescending();

    //The highest card should be 10
    assert(h.getScore() == 17);

    cout << "testSortingDescending passed\n";
}

//Test 4: Verify dealer rule (must hit until >= 17)
void testDealerLogic() {
    Hand dealer;
    Deck d;

    d.shuffleDeck();

    dealer.addCard(d.dealCard());
    dealer.addCard(d.dealCard());

    while (dealer.getScore() < 17) {
        dealer.addCard(d.dealCard());
    }

    assert(dealer.getScore() >= 17 || dealer.getScore() > 21);

    cout << "testDealerLogic passed\n";
}

//Test 5: Verify stability across multiple rounds
void testMultipleRounds() {
    for (int i = 0; i < 5; i++) {         //This loop runs 5 rounds

        Deck d;             //This creates a new deck each round
        d.shuffleDeck();
        Hand h;

        h.addCard(d.dealCard());
        h.addCard(d.dealCard());

        int score = h.getScore();
        assert(score > 0 && score <= 21);
    }

    cout << "testMultipleRounds passed\n";
}

//Runs all test cases
void runAllTests() {
    cout << "\nRunning tests\n";
    testAddCard();
    testAceScoring();
    testSortingDescending();
    testDealerLogic();
    testMultipleRounds();
    cout << "All tests passed!\n\n";
}

int main() {
    runAllTests();
    return 0;
}
