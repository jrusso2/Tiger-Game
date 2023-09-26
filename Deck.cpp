#include "Deck.h"

Deck::Deck() {
    // Add 10 purple cards and 10 orange cards to the deck
    for (int i = 1; i <= 10; i++) {
        deck.push_back(Card(i, Card::purple));
        deck.push_back(Card(i, Card::orange));
    }
}

void Deck::shuffle() {
    // Shuffle the deck using the std::shuffle algorithm and a random seed
    std::srand(std::time(nullptr));
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard() {
    // Get the first card in the deck, remove it from the deck, and return it
    Card drawnCard = deck.front();
    deck.erase(deck.begin());
    return drawnCard;
}

int Deck::getDeckSize() {
    // Return the current size of the deck
    return deck.size();
}