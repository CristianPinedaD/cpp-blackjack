#include "card.h"



Deck createDeck() {
	Deck deck;
	vector<string> suits = {"Spades", "Hearts", "Clubs", "Diamonds"};

	for (string suit : suits) {
		for (int i = 0; i < 12; i++) {
			Card card = Card(suit, i);
			deck.push_back(card);
		}
	}

	return deck;
}