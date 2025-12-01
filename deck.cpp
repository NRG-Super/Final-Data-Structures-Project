//Deck.cpp

#include "Deck.h"
#include <algorithm>
#include <random>
#include <stdexcept>

Deck::Deck() {
    reset();
}

void Deck::reset() {
    cards.clear();
    std::vector<std::string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    std::vector<char> suits = {'S', 'H', 'D', 'C' };

    for (const auto& rank : ranks) {
        for (char suit : suits) {
            int v = (rank == "A") ? 11 : (rank == "J" || rank == "Q" || rank == "K") ? 10 : std::stoi(rank);
            cards.emplace_back(rank, suit, v);
        }
    }
}

Card Deck::dealCard() {
    if (cards.empty()) throw std::runtime_error("Deck empty!");

    Card c = cards.back();
    cards.pop_back();
    return c;
}

bool Deck::isEmpty() const {
    return cards.empty();
}


