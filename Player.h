// Note: There is no Player.cpp file.
// The player class is simple enough to
// implement everything in Player.h

#ifndef PLAYER_H_
#define PLAYER_H_

class Player
{
 public:
    Hand hand;
    int score = 0;
    Player();
    Player(Deck& deck, int N);
};

Player::Player() {}

Player::Player(Deck& deck, int N) {
    hand = Hand(deck, N);  
};
  

#endif // PLAYER_H_
