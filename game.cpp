#include "card.h"

int main(void) {
	string playerName;

	cout << "Please enter your name: ";
	cin >> playerName;

	Deck playerDeck;
	Deck dealerDeck;
	Deck gameDeck = createDeck();
	Player player = {playerName, playerDeck, 0};
	Player dealer = {"Dealer", dealerDeck, 0}; 

    while (player.staying == 0) {
		cout << "You currently have the following cards:" << endl;
		checkCards(player.deck); 
		cout << "Would you like to: " << endl;
		cout << "(1) Hit\n(2) Stay" << endl;
		cout << "Choose your option: ";
		int option = 0;
		cin >> option; 

        while (option != 1 || option != 2) {
			cout << "Would you like to: " << endl;
			cout << "(1) Hit\n(2) Stay" << endl;
			cin >> option; 
		}

        switch (option) {
            case 1:
				player.deck = hit(player.deck, gameDeck);
				break;
			case 2:
				player.staying = 1;
				break;
		}

		dealerPlay(gameDeck, dealer); 
	}
}