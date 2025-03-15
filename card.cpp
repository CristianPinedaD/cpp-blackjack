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

Deck shuffleDeck(Deck sorted) {
	random_device rd;
	mt19937 g(rd());

	shuffle(sorted.begin(), sorted.end(), g);
}

Deck hit(Deck &playerDeck, Deck &gameDeck) {
	gameDeck = shuffleDeck(gameDeck);

	if (playerDeck.size() == 0) {
		playerDeck.push_back(gameDeck.back());
		gameDeck.pop_back();
		playerDeck.push_back(gameDeck.back());
		gameDeck.pop_back();
		gameDeck = shuffleDeck(gameDeck);
	}
    else {
		playerDeck.push_back(gameDeck.back());
		gameDeck.pop_back(); 
	}
}