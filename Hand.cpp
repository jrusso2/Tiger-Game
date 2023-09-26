#include "Hand.h"

Hand::Hand() {}

Hand::Hand(Deck& deck, int N) {
    // Draw N cards from the deck and add them to the hand
    for (int i = 0; i < N; i++) {
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::printHand() {
    std::stringstream ss;
    // Iterate over the hand vector and append each card's string representation to the output stream
    for (std::vector<Card>::size_type i = 0; i < hand.size(); i++) {
        ss << "[" << i + 1 << "] " << hand[i].printCard() << " ";
    }
    return ss.str();
}


Card Hand::dealCard(int num) {
    // Remove the card at position num from the hand vector and return it
    Card dealtCard = hand[num - 1];
    hand.erase(hand.begin() + num - 1);
    return dealtCard;
}

int Hand::getHandSize() {
    // Return the current size of the hand vector
    return hand.size();
}
