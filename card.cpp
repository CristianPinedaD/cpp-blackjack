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

int checkWin(Deck playerDeck, Deck dealerDeck) {
	int playerValue = getDeckValue(playerDeck);
	int dealerValue = getDeckValue(dealerDeck);

	int playerWin; // 0 if won, 1 if lost
	int dealerWin; // 0 if won, 1 if lost

	if (playerValue > dealerValue) {
		/* Player didn't go bust */
		if (playerValue <= 21) {
			playerWin = 0;
			dealerWin = 1;
			/* Player went bust */
		} else {
			playerWin = 1;
		}
	} else if (playerValue < dealerValue) {
		/* Dealer didn't go bust*/
		if (dealerValue <= 21) {
			dealerWin = 1;
			playerWin = 0;
			/* Dealer went bust */
		} else {
			dealerWin = 1;
		}
        /* They tied so they both lost */
	} else {
        /* Tied but under the threshold */
		if (playerValue <= 21) {
			playerWin = 0;
			dealerWin = 0;
		}
        /* Both went bust */
        else {
			playerWin = 1;
			dealerWin = 1;
		}
	}

	/* If they didn't tie */
	if (playerWin != dealerWin) {
		if (playerWin == 0) {
			return 0;
		} else {
			return 1;
		}
	}

	/* If they tied */
	if (playerWin == dealerWin) {
		if (playerWin = 0) {
			return 2;
		}
		/* Both went bust */
		else {
			return 1;
		}
	}
}

void stay(Player &player) {
	player.stay = 1;
}

void dealerPlay(Deck &gameDeck, Player &dealer) {

	Deck dealerDeck = dealer.deck; 

	if (getDeckValue(dealerDeck) <= 17) {
		hit(dealer.deck, gameDeck); 
	}
    else {
		stay(dealer); 
	}
}
