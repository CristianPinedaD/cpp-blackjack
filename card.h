#ifndef CARD_H
#define CARD_H

#include <string> 
#include <iostream> 
#include <vector>
#include <algorithm>
#include <random>

using namespace std; 

/* A card is simply A-10, j, q, k*/
/* For BlackJack, all face cards except the Ace are worth 10*/
/* The ace is worth 1 or 11 depending on what you need */

class Card {

    private:
	  string suit; // Hearts, Clubs, Spades, Diamonds
      int type; // A-10, J, Q, K
	public:
	  Card(string suit, int value) : suit(suit), type(value) {}

	  void setValue(int value);
	  void setSuit(string suit); 
	  int getValue();
	  string getSuit(); 

};

/* A deck holds 52 cards */
/* That's 13 cards in each suit */
typedef vector<Card> Deck;

struct player {
	string name;
	Deck deck;
	int staying; // 1 if they're staying
};

typedef struct player Player;

/*
    Creates an unshuffled deck of cards
*/
Deck createDeck();

Deck shuffleDeck(Deck sorted);

Deck hit(Deck &playerDeck, Deck &gameDeck);

void checkCards(Deck playerDeck); 

int isBust(player);

int getDeckValue(Deck deck); 

void stay(Player &player);

/*
Returns: 

	0 if Player won
	1 if Dealer won
	2 if it's a tie
	3 if both went bust

*/
int checkWin(Player &player, Player &dealer);

void dealerPlay(Deck &gameDeck, Player &dealer);

void dealerPeek(Deck dealerDeck); 

#endif