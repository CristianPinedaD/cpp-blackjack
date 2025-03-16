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


		dealerPlay(gameDeck, dealer); 
		cout << "Dealer peeks: " << endl;
		dealerPeek(dealer.deck);
		cout << "------------------------------------" << endl;

		cout << "You currently have the following cards:" << endl;

		player.deck = hit(player.deck, gameDeck); 
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

		if (checkWin(player, dealer) == 1) {
			checkCards(player.deck);
			break; 
		}
	}

	dealerPlay(gameDeck, dealer);

	int winner = checkWin(player, dealer); 

	switch (winner) {
		case 0:
			system("clear");

			cout << "Your hand: " << endl;
			checkCards(player.deck);
			cout << "------------------------------" << endl;
			cout << "The dealer's hand: " << endl;
			checkCards(dealer.deck);
			cout << "------------------------------" << endl;
			cout << "Congratulations " << player.name << ", you win!" << endl;
			break;
		case 1:
			system("clear");

			cout << "Your hand: " << endl;
			checkCards(player.deck);
			cout << "------------------------------" << endl;
			cout << "The dealer's hand: " << endl;
			checkCards(dealer.deck);
			cout << "------------------------------" << endl;
			cout << "Womp womp, dealer won." << endl;
			break;
		case 2:
			system("clear");
			
			cout << "It's a tie!" << endl;
			break;

		case 3:
			system("clear");

			cout << "Wow, you both went bust." << endl;
			break; 
	}
}