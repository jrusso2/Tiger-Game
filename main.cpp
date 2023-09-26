#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>

using namespace std;

int main() {

  cout << "Welcome to TigerGame!" << endl;

  int totalRounds = 0;
  int humanTotalScore = 0;
  int computerTotalScore = 0;
  int humanTotalWins = 0;
  int computerTotalWins = 0;
  int play = 1;

  do 
  {
    // Create a deck of cards and shuffle it.
    Deck deckOfCards;
    deckOfCards.shuffle();
  
    // Create two players, each one with N cards in their hand.
    int N;
    cout << "How many cards should each player draw from the deck?" << endl;
    cin >> N;
    while (N > deckOfCards.getDeckSize()/2) 
    {
      cout << "Invalid input. There are not enough cards in the deck. Please enter a smaller number:" << endl;
      cin >> N;
    }

    Player humanPlayer(deckOfCards, N);
    Player computerPlayer(deckOfCards, N);

    int numRounds = N;
    cout << "Each player will draw " << N << " cards from the deck." << endl;
    cout << "A total of " << numRounds << " rounds will be played." << endl;

    int humanScore = 0;
    int computerScore = 0;

    for (int round = 1; round <= numRounds; round++) 
    {
      cout << "Round " << round << endl;
      cout << "-------" << endl;

      // Computer plays a card
      Card computerCard = computerPlayer.hand.dealCard(1);
      cout << "The computer plays: " << computerCard.printCard() << endl;

      // Human plays a card
      cout << "Your hand: " << humanPlayer.hand.printHand() << endl;
      int num;
      cout << "Which card do you want to play? ";
      cin >> num;
      while (num < 1 || num > humanPlayer.hand.getHandSize()) 
      {
        cout << "Invalid input. Please enter a number between 1 and " << humanPlayer.hand.getHandSize() << ": ";
        cin >> num;
      }

      Card humanCard = humanPlayer.hand.dealCard(num);
      cout << "You played: " << humanCard.printCard() << endl;

      // Determine the winner of the round
      int roundScore = 0;
      if (humanCard.getValue() > computerCard.getValue()) 
      {
        cout << "You win this round!" << endl;
        roundScore = humanCard.getValue() + computerCard.getValue();
        humanScore += roundScore;
      }
      else if (humanCard.getValue() < computerCard.getValue()) 
      {
        cout << "The computer wins this round!" << endl;
        roundScore = humanCard.getValue() + computerCard.getValue();
        computerScore += roundScore;
      }
      else 
      {
        cout << "Tie!" << endl;
      }

      // Print the current scores
      cout << "Current scores:" << endl;
      cout << "Human: " << humanScore << endl;
      cout << "Computer: " << computerScore << endl;
      cout << endl;
    }

    // Print the final game results
    cout << "FINAL SCORE:" << endl;
    cout << "Human: " << humanScore << endl;
    cout << "Computer: " << computerScore << endl;

    if (humanScore > computerScore) {
      cout << "Human has won!" << endl;
      totalRounds++;
      humanTotalWins++;
      humanTotalScore += humanScore;
      computerTotalScore += computerScore;
    }
    else if (humanScore < computerScore) {
      cout << "Computer has won!" << endl;
      totalRounds++;
      computerTotalWins++;
      humanTotalScore += humanScore;
      computerTotalScore += computerScore;
    }
    else {
      cout << "The game is a tie!" << endl;
      totalRounds++;
    }

    cout << "Play again? Type 1 for yes, 0 for no" << endl;
    cin >> play;
    
  } while (play == 1);

    cout << endl << "GAME SUMMARY:" << endl;
    cout << "Total rounds played: " << totalRounds << endl;
    cout << "Human rounds won: " << humanTotalWins << endl;
    cout << "Human total score: " << humanTotalScore << endl;
    cout << "Computer rounds won: " << computerTotalWins << endl;
    cout << "Computer total score: " << computerTotalScore << endl;

  return 0;
}