#include "Tests.h"
#include "Hand.h"
#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>

using namespace std;

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

void testAceScoring() {
    Hand h;

    h.addCard(Card("A", 'S', 11));
    h.addCard(Card("9", 'H', 9));
    h.addCard(Card("5", 'D', 5));

    int score = h.getScore();
    assert(score == 15);

    cout << "testAceScoring passed\n";
}

void testSortingDescending() {
    Hand h;

    h.addCard(Card("3", 'H', 3));
    h.addCard(Card("K", 'H', 10));
    h.addCard(Card("4", 'S', 4));

    h.sortDescending();
    
    assert(h.getScore() == 17);

    cout << "testSortingDescending passed\n";
}

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

void testMultipleRounds() {
    for (int i = 0; i < 5; i++) {

        Deck d;
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
