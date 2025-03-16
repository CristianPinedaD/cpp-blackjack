#include "card.h"

string Card::getSuit() {
	return this->suit;
}

int Card::getValue() {
	return this->type;
}

void Card::setSuit(string suit) {
	this->suit = suit;
}

void Card::setValue(int value) {
	this->type = value;
}

Deck createDeck() {
	Deck deck;
	vector<string> suits = {"Spades", "Hearts", "Clubs", "Diamonds"};

	for (string suit : suits) {
		for (int i = 0; i < 13; i++) {
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

	return sorted;
}

Deck hit(Deck &playerDeck, Deck &gameDeck) {
	gameDeck = shuffleDeck(gameDeck);

	if (playerDeck.size() == 0) {
		playerDeck.push_back(gameDeck.back());
		gameDeck.pop_back();
		playerDeck.push_back(gameDeck.back());
		gameDeck.pop_back();
		gameDeck = shuffleDeck(gameDeck);
	} else {
		playerDeck.push_back(gameDeck.back());
		gameDeck.pop_back();

		gameDeck = shuffleDeck(gameDeck); 
	}

	return playerDeck;
}

void dealerPeek(Deck dealerDeck) {
	Card card = dealerDeck.back();

	string suit = card.getSuit();

	if (card.getValue() >= 2 && card.getValue() <= 10) {
		cout << card.getValue() << " of " << suit << "." << endl;
	} else {
		switch (card.getValue()) {
			case 0:
				cout << "Ace of " << suit << "." << endl;
				break;

			case 1:
				cout << "Jack of " << suit << "." << endl;
				break;
			case 11:
				cout << "Queen of " << suit << "." << endl;
				break;
			case 12:
				cout << "King of " << suit << "." << endl;
				break;
		}
	}
}

void checkCards(Deck playerDeck) {
	for (Card card : playerDeck) {
		string suit = card.getSuit();
		if (card.getValue() >= 2 && card.getValue() <= 10) {
			cout << card.getValue() << " of " << suit << "." << endl;
		} else {
			switch (card.getValue()) {
				case 0:
					cout << "Ace of " << suit << "." << endl;
					break;

				case 1:
					cout << "Jack of " << suit << "." << endl;
					break;
				case 11:
					cout << "Queen of " << suit << "." << endl;
					break;
				case 12:
					cout << "King of " << suit << "." << endl;
					break;
			}
		}
	}
}

int isBust(Player player) {
	if (getDeckValue(player.deck) > 21) {
		return 1;
	}
	else {
		return 0; 
	}
}

/* A helper for checkWin() */
int getDeckValue(Deck deck) {

	int total = 0;
	for (Card card : deck) {
		if (card.getValue() >= 2 && card.getValue() <= 10) {
			total += card.getValue();
		} else if (card.getValue() == 0) {
			if (total <= 10) {
				total += 11;
			} else {
				total += 1;
			}
		} else {
			total += 10;
		}
	}
	return total;
}

/*
	Returns:
		0 if the player won
		1 if the dealer won 
		2 if it was a tie
		3 if both went bust
*/
int checkWin(Player &player, Player &dealer) {
	int playerValue = getDeckValue(player.deck);
	int dealerValue = getDeckValue(dealer.deck);

	if (isBust(player) && isBust(dealer)) {
		return 3; 
	}

	else if (isBust(player) && !isBust(dealer)) {
		return 1; 
	}
	else if (!isBust(player) && isBust(dealer)) {
		return 0;
	}

	else {
		if (getDeckValue(player.deck) > getDeckValue(dealer.deck)) {
			return 0; 
		}
		if (getDeckValue(player.deck) < getDeckValue(dealer.deck)) {
			return 1; 
		}
		else {
			return 2;
		}
	}
}

void dealerPlay(Deck &gameDeck, Player &dealer) {

	Deck dealerDeck = dealer.deck;

	if (getDeckValue(dealerDeck) <= 17) {
		hit(dealer.deck, gameDeck);
		if (!dealer.deck.empty()) cout << "Dealer hits..." << endl; 
	} else {
		dealer.staying = 1;
		cout << "Dealer stays..." << endl; 
	}
}
