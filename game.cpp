#include "card.h"
#include <cstdlib>

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
		system("clear"); 
		cout << "You currently have the following cards:" << endl;
		checkCards(player.deck); 
		cout << "Would you like to: " << endl;
		cout << "(1) Hit\n(2) Stay" << endl;
		cout << "Choose your option: ";
		int option = 0;
		cin >> option; 

        switch (option) {
            case 1:
				player.deck = hit(player.deck, gameDeck);
				break;
			case 2:
				player.staying = 1;
				break;
		}

		dealerPlay(gameDeck, dealer);

		cout << "Dealer has: " << endl;
		dealerPeek(dealer.deck); 

		if (checkWin(player.deck, dealer.deck) == 1) {
			checkCards(player.deck);
			break; 
		}
	}

	int winner = checkWin(player.deck, dealer.deck); 

	switch (winner) {
		case 0:
			cout << "Congratulations " << player.name << ", you win!" << endl; 
			break;
		case 1:
			cout << "Womp womp, dealer won." << endl;
			break;
		case 2:
			cout << "It's a tie!" << endl; 
			break;
	}
}