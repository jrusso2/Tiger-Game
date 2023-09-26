#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "Card.h"

class Deck
{
public:
    Deck();
    void shuffle();
    Card drawCard();
    int getDeckSize();
private:
    std::vector<Card> deck;
};

#endif // DECK_H_
