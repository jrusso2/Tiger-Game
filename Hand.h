#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>
#include <sstream>
#include "Card.h"
#include "Deck.h"

class Hand
{
public:
    Hand();
    Hand(Deck& deck, int N);
    std::string printHand();
    Card dealCard(int num);
    int getHandSize();
private:
    std::vector<Card> hand;
};

#endif // HAND_H_
