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
	  int getSuit(); 

};

/* A deck holds 52 cards */
/* That's 13 cards in each suit */
typedef vector<Card> Deck;

/*
    Creates an unshuffled deck of cards
*/
Deck createDeck();

Deck shuffleDeck(Deck sorted); 



#endif CARD_H