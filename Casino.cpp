#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
/*
	Project1.h
	Robert Griffin
	version 1.0

	A casino for Bob
	Plays various games including: Flip the coin, Guess the number, Street craps, Blackjack
	Keeps track of your wallet
	Notifies you of your winnings
*/

std::vector<std::string> _cards;
void displayMenu();
void shuffleCards();
void printCards();
int getCardValue(std::string card);
std::string getSuit(std::string card);
std::string drawCard();

void seedRand(int seed);
void printMoney(double money);
void printWallet(double wallet);
void payMoney(double & wallet, double amount);
void winMoney(double & wallet, double amount);
int getRandomNumber(int min, int max);
double placeBet(double & wallet, double & bet);

void playFlipTheCoin(double & wallet);
void playGuessTheNumber(double & wallet);
void playStreetCraps(double & wallet);
void playBlackjack(double & wallet);

int main()
{
	// You need money to spend on the games
	double wallet = 20.00;

	srand(time(0));

	char gameSelection = ' ';

	do
	{
	start:
		displayMenu();
		std::cin >> gameSelection;
		std::cout << "\n";

		switch (gameSelection)
		{
		case 'F':
		case 'f':
			playFlipTheCoin(wallet);
			break;
		case 'G':
		case 'g':
			playGuessTheNumber(wallet);
			break;
		case 'S':
		case 's':
			playStreetCraps(wallet);
			break;
		case 'B':
		case 'b':
			playBlackjack(wallet);
			break;
		case 'X':
		case 'x':
			goto casinoExit;
			break;
		default:
			gameSelection != 'X' || 'x';
			break;
		}
	}

	while (gameSelection != 'X' || 'x');

casinoExit:

	printWallet(wallet);

	std::cout << "\n";
	std::cout << "\n";



	//code to stop the window from closing.
	std::cout << "Press ENTER to continue";
	std::cin.ignore();
	std::cin.get();
}

void displayMenu()
{
	const int nameWidth = 20;
	const int priceWidth = 8;

	std::cout << "Welcome to Bob's Casino" << "\n";
	std::cout << "What game do you want to play?" << "\n";
	std::cout << std::setw(nameWidth) << std::left << "Name";
	std::cout << std::setw(priceWidth) << std::left << "Price";
	std::cout << "Odds" << "\n";

	// Print flip the coin details
	std::cout << std::setw(nameWidth) << std::left << "(F)lip-the-Coin";
	std::cout << std::setw(priceWidth) << std::left << "$0.50";
	std::cout << "2/1" << "\n";

	// Print guess the number details
	std::cout << std::setw(nameWidth) << std::left << "(G)uess-the-Number";
	std::cout << std::setw(priceWidth) << std::left << "$1.00";
	std::cout << "2/1" << "\n";

	// Print street craps details
	std::cout << std::setw(nameWidth) << std::left << "(S)treet Craps";
	std::cout << std::setw(priceWidth) << std::left << "Wager";
	std::cout << "2/1" << "\n";

	// Print blackjack details
	std::cout << std::setw(nameWidth) << std::left << "(B)lackjack";
	std::cout << std::setw(priceWidth) << std::left << "Wager";
	std::cout << "2/1 (4/1 for Blackjack!)" << "\n";

	// Print exit details
	std::cout << "E(x)it" << "\n";
	std::cout << "Selection (F,G,S,B,X): ";
}

void playFlipTheCoin(double & wallet)
{
	std::cout << "Welcome to the flip-a-coin game!" << "\n";
	payMoney(wallet, 0.50);
	printMoney(.50);
	std::cout << "\n";

	char playerGuess = ' ';

	std::cout << "Guess (H)eads or (T)ails: ";
	std::cin >> playerGuess;


	int coinFlip = 0;
	coinFlip = getRandomNumber(1, 2);

	std::string coinSide;


	if (coinFlip == 1)
	{
		coinSide = "heads";
	}
	if (coinFlip == 2)
	{
		coinSide = "tails";
	}

	std::cout << "The coin landed on " << coinSide << ".\n";


	switch (playerGuess)
	{
	case 'H':
	case 'h':
		if (coinFlip == 1)
		{
			std::cout << "You guessed heads...right!" << "\n";
			std::cout << "You just won $1.00" << "\n";
			winMoney(wallet, 1.00);
			break;
		}
		else
		{
			std::cout << "You guessed heads...wrong!! Haha!" << "\n";
			break;
		}
	case 'T':
	case 't':
		if (coinFlip == 2)
		{
			std::cout << "You guessed tails...right!" << "\n";
			std::cout << "You just won $1.00" << "\n";
			winMoney(wallet, 1.00);
			break;
		}
		else
		{
			std::cout << "You guessed tails...wrong!! Haha!" << "\n";
			break;
		}
	default:
		std::cout << "Invalid Selection";
		break;

	}

	std::cout << "\n";

	printWallet(wallet);

	std::cout << "\n";
	std::cout << "\n";

}

void playGuessTheNumber(double & wallet)
{
	std::cout << "Welcome to guess the number!" << "\n";
	payMoney(wallet, 1.00);
	printMoney(1.00);
	std::cout << "\n";

	int secretNumber = 0;
	secretNumber = getRandomNumber(1, 100);

	int playerGuess = 0;

	std::cout << "I have my secret number between 1 and 100" << "\n";
	std::cout << "You get 10 guesses" << "\n";

	for (int i = 1; i < 11; i++)
	{
		std::cout << "What do you guess (" << i << ")? ";
		std::cin >> playerGuess;
		if (secretNumber == playerGuess)
		{
			std::cout << "Congratulations!" << "\n";
			std::cout << "You just won $2.00" << "\n";
			winMoney(wallet, 2.00);
			break;
		}
		if (secretNumber > playerGuess)
		{
			std::cout << "My number is higher" << "\n";
		}
		else
		{
			std::cout << "My number is lower" << "\n";
		}
	}

	std::cout << "\n";
	printWallet(wallet);
	std::cout << "\n";
	std::cout << "\n";

}

void playStreetCraps(double & wallet)
{
	double bet = 0;
	std::cout << "Welcome to street craps!" << "\n";
	printWallet(wallet);
	std::cout << "\n";
	placeBet(wallet, bet);
	std::cout << "\n";



	int diceOne = 0;
	int diceTwo = 0;
	int diceResult = 0;
	int pointRoll = 0;



	diceOne = getRandomNumber(1, 6);
	diceTwo = getRandomNumber(1, 6);
	diceResult = diceOne + diceTwo;

	std::cout << "You rolled " << diceOne << " + " << diceTwo << " = " << diceResult << "\n";

	if (diceResult == 2)
	{
		std::cout << "You rolled a 2! You lose!! Haha!" << "\n";
	}
	if (diceResult == 3)
	{
		std::cout << "You rolled a 3! You lose!! Haha!" << "\n";
	}
	if (diceResult == 7)
	{
		std::cout << "You win!!" << "\n";
		std::cout << "You just won $" << (bet * 2);
		winMoney(wallet, (bet * 2));
		goto end;
	}
	if (diceResult == 11)
	{
		std::cout << "You win!!" << "\n";
		std::cout << "You just won $" << (bet * 2);
		winMoney(wallet, (bet * 2));
		goto end;
	}
	if (diceResult == 12)
	{
		std::cout << "You rolled a 12! You lose!! Haha!" << "\n";
	}
	else
	{
		std::cout << "Point roll is now " << diceResult << "\n";
		pointRoll = diceResult;
	}


	do
	{
		diceOne = getRandomNumber(1, 6);
		diceTwo = getRandomNumber(1, 6);
		diceResult = diceOne + diceTwo;

		std::cout << "You rolled " << diceOne << " + " << diceTwo << " = " << diceResult << "\n";

	} while (diceResult != pointRoll && diceResult != 7 && diceResult != 11);

	if (diceResult == pointRoll)
	{
		std::cout << "You win!!" << "\n";
		std::cout << "You just won $" << (bet * 2);
		winMoney(wallet, (bet * 2));
		goto end;
	}
	if (diceResult == 7)
	{
		std::cout << "You rolled a 7! You lose!! Haha!";
	}
	if (diceResult == 11)
	{
		std::cout << "You rolled an 11! You lose!! Haha!";
	}
end:

	std::cout << "\n";
	std::cout << "\n";
	printWallet(wallet);
	std::cout << "\n";
	std::cout << "\n";
}

void playBlackjack(double & wallet)
{
	double bet = 0;
	std::cout << "Welcome to blackjack!" << "\n";
	printWallet(wallet);
	std::cout << "\n";
	placeBet(wallet, bet);
	std::cout << "\n";

	shuffleCards();
	std::string card1 = drawCard();
	std::string card2 = drawCard();
	std::cout << "You drew: " << card1 << "\n";
	std::cout << "You drew: " << card2 << "\n";

	int card1Value = getCardValue(card1);
	int card2Value = getCardValue(card2);
	int cardTotal = card1Value + card2Value;
	std::cout << "Total: " << cardTotal << "\n";

	char playerChoice = ' ';


	do
	{
		do
		{

			std::cout << "(H)it or (S)tand?: ";
			std::cin >> playerChoice;

			if (playerChoice == 'H' || playerChoice == 'h')
			{
				std::string card3 = drawCard();
				std::cout << "You drew: " << card3 << "\n";
				int card3Value = getCardValue(card3);
				cardTotal = cardTotal + card3Value;
				std::cout << "Total: " << cardTotal << "\n";

				if (cardTotal == 21)
				{
					std::cout << "You got 21! Congratulations!" << "\n";
					std::cout << "You just won $" << (bet * 4);
					winMoney(wallet, (bet * 4));
					goto BJend;
				}
				if (cardTotal < 21)
				{
					do
					{
						playerChoice = ' ';
						std::cout << "(H)it or (S)tand?: ";
						std::cin >> playerChoice;

						if (playerChoice == 'H' || playerChoice == 'h')
						{
							std::string card4 = drawCard();
							std::cout << "You drew: " << card4 << "\n";
							int card4Value = getCardValue(card4);
							cardTotal = cardTotal + card4Value;
							std::cout << "Total: " << cardTotal << "\n";

							if (cardTotal == 21)
							{
								std::cout << "You got 21! Congratulations!" << "\n";
								std::cout << "You just won $" << (bet * 4);
								winMoney(wallet, (bet * 4));
								goto BJend;
							}
							if (cardTotal < 21)
							{
								do
								{
									playerChoice = ' ';
									std::cout << "(H)it or (S)tand?: ";
									std::cin >> playerChoice;

									if (playerChoice == 'H' || playerChoice == 'h')
									{
										std::string card5 = drawCard();
										std::cout << "You drew: " << card5 << "\n";
										int card5Value = getCardValue(card5);
										cardTotal = cardTotal + card5Value;
										std::cout << "Total: " << cardTotal << "\n";

										if (cardTotal == 21)
										{
											std::cout << "You got 21! Congratulations!" << "\n";
											std::cout << "You just won $" << (bet * 4);
											winMoney(wallet, (bet * 4));
											goto BJend;
										}
										if (cardTotal < 21)
										{
											do
											{
												playerChoice = ' ';
												std::cout << "(H)it or (S)tand?: ";
												std::cin >> playerChoice;

												if (playerChoice == 'H' || playerChoice == 'h')
												{
													std::string card6 = drawCard();
													std::cout << "You drew: " << card6 << "\n";
													int card6Value = getCardValue(card6);
													cardTotal = cardTotal + card6Value;
													std::cout << "Total: " << cardTotal << "\n";

													if (cardTotal == 21)
													{
														std::cout << "You got 21! Congratulations!" << "\n";
														std::cout << "You just won $" << (bet * 4);
														winMoney(wallet, (bet * 4));
														goto BJend;
													}
													if (cardTotal < 21)
													{
														do
														{
															playerChoice = ' ';
															std::cout << "(H)it or (S)tand?: ";
															std::cin >> playerChoice;

															if (playerChoice == 'H' || playerChoice == 'h')
															{
																std::string card7 = drawCard();
																std::cout << "You drew: " << card7 << "\n";
																int card7Value = getCardValue(card7);
																cardTotal = cardTotal + card7Value;
																std::cout << "Total: " << cardTotal << "\n";

																if (cardTotal == 21)
																{
																	std::cout << "You got 21! Congratulations!" << "\n";
																	std::cout << "You just won $" << (bet * 4);
																	winMoney(wallet, (bet * 4));
																	goto BJend;
																}

																if (cardTotal < 21)
																{
																	goto BJend;
																}
																if (cardTotal > 21)
																{
																	std::cout << "You busted!! Hahaha!";

																	goto BJend;
																}
															}
															if (playerChoice == 'S' || playerChoice == 's')
															{
																goto stand;
															}

														} while (playerChoice != 'H' || playerChoice != 'h' && playerChoice != 'S' || playerChoice != 's');
													}
													if (cardTotal > 21)
													{
														std::cout << "You busted!! Hahaha!";

														goto BJend;
													}
												}
												if (playerChoice == 'S' || playerChoice == 's')
												{
													goto stand;
												}

											} while (playerChoice != 'H' || playerChoice != 'h' && playerChoice != 'S' || playerChoice != 's');
										}
										if (cardTotal > 21)
										{
											std::cout << "You busted!! Hahaha!";

											goto BJend;
										}
									}
									if (playerChoice == 'S' || playerChoice == 's')
									{
										goto stand;
									}

								} while (playerChoice != 'H' || playerChoice != 'h' && playerChoice != 'S' || playerChoice != 's');
							}
							if (cardTotal > 21)
							{
								std::cout << "You busted!! Hahaha!";

								goto BJend;
							}
						}
						if (playerChoice == 'S' || playerChoice == 's')
						{
							goto stand;
						}

					} while (playerChoice != 'H' || playerChoice != 'h' && playerChoice != 'S' || playerChoice != 's');
				}
				if (cardTotal > 21)
				{
					std::cout << "You busted!! Hahaha!";

					goto BJend;
				}

			}
			if (playerChoice == 'S' || playerChoice == 's')
			{
			stand:
				std::cout << "You are standing on " << cardTotal << "\n";
				std::cout << "Ok now it's the dealer's turn" << "\n";

				std::string dCard1 = drawCard();
				std::string dCard2 = drawCard();
				std::cout << "The dealer drew the " << dCard1 << "\n";
				std::cout << "The dealer drew the " << dCard2 << "\n";

				int dCard1Value = getCardValue(dCard1);
				int dCard2Value = getCardValue(dCard2);
				int dCardTotal = dCard1Value + dCard2Value;
				std::cout << "Dealer total: " << dCardTotal << "\n";

				if (dCardTotal < 17)
				{
					std::string dCard3 = drawCard();
					std::cout << "The dealer drew the " << dCard3 << "\n";
					int dCard3Value = getCardValue(dCard3);
					dCardTotal = dCardTotal + dCard3Value;
					std::cout << "Dealer total: " << dCardTotal << "\n";

					if (dCardTotal < 17)
					{
						std::string dCard4 = drawCard();
						std::cout << "The dealer drew the " << dCard4 << "\n";
						int dCard4Value = getCardValue(dCard4);
						dCardTotal = dCardTotal + dCard4Value;
						std::cout << "Dealer total: " << dCardTotal << "\n";

						if (dCardTotal < 17)
						{
							std::string dCard5 = drawCard();
							std::cout << "The dealer drew the " << dCard5 << "\n";
							int dCard5Value = getCardValue(dCard5);
							dCardTotal = dCardTotal + dCard5Value;
							std::cout << "Dealer total: " << dCardTotal << "\n";

							if (dCardTotal < 17)
							{
								std::string dCard6 = drawCard();
								std::cout << "The dealer drew the " << dCard6 << "\n";
								int dCard6Value = getCardValue(dCard6);
								dCardTotal = dCardTotal + dCard6Value;
								std::cout << "Dealer total: " << dCardTotal << "\n";
							}
							if (dCardTotal > 16)
							{
								if (dCardTotal == cardTotal)
								{
									std::cout << "That was a push" << "\n";
									std::cout << "You just won $" << bet;
									winMoney(wallet, bet);
									goto BJend;
								}
								if (dCardTotal < cardTotal)
								{
									std::cout << "You win!!!" << "\n";
									std::cout << "You just won $" << (bet * 2);
									winMoney(wallet, (bet * 2));
									goto BJend;
								}
								if (dCardTotal > cardTotal)
								{
									std::cout << "Dealer wins!" << "\n";
									goto BJend;
								}
							}
							if (dCardTotal == 21)
							{
								std::cout << "Dealer wins!" << "\n";
							}
							if (dCardTotal > 21)
							{
								std::cout << "Dealer busted! You win!" << "\n";
								std::cout << "You just won $" << bet;
								winMoney(wallet, bet);
								goto BJend;
							}
						}
						if (dCardTotal > 16)
						{
							if (dCardTotal == cardTotal)
							{
								std::cout << "That was a push" << "\n";
								std::cout << "You just won $" << bet;
								winMoney(wallet, bet);
								goto BJend;
							}
							if (dCardTotal < cardTotal)
							{
								std::cout << "You win!!!" << "\n";
								std::cout << "You just won $" << (bet * 2);
								winMoney(wallet, (bet * 2));
								goto BJend;
							}
							if (dCardTotal > cardTotal)
							{
								std::cout << "Dealer wins!" << "\n";
								goto BJend;
							}
						}
						if (dCardTotal == 21)
						{
							std::cout << "Dealer wins!" << "\n";
						}
						if (dCardTotal > 21)
						{
							std::cout << "Dealer busted! You win!" << "\n";
							std::cout << "You just won $" << bet;
							winMoney(wallet, bet);
							goto BJend;
						}
					}
					if (dCardTotal > 16)
					{
						if (dCardTotal == cardTotal)
						{
							std::cout << "That was a push" << "\n";
							std::cout << "You just won $" << bet;
							winMoney(wallet, bet);
							goto BJend;
						}
						if (dCardTotal < cardTotal)
						{
							std::cout << "You win!!!" << "\n";
							std::cout << "You just won $" << (bet * 2);
							winMoney(wallet, (bet * 2));
							goto BJend;
						}
						if (dCardTotal > cardTotal)
						{
							std::cout << "Dealer wins!" << "\n";
							goto BJend;
						}
					}
					if (dCardTotal == 21)
					{
						std::cout << "Dealer wins!" << "\n";
					}
					if (dCardTotal > 21)
					{
						std::cout << "Dealer busted! You win!" << "\n";
						std::cout << "You just won $" << bet;
						winMoney(wallet, bet);
						goto BJend;
					}
				}
				if (dCardTotal > 16)
				{
					if (dCardTotal == cardTotal)
					{
						std::cout << "That was a push" << "\n";
						std::cout << "You just won $" << bet;
						winMoney(wallet, bet);
						goto BJend;
					}
					if (dCardTotal < cardTotal)
					{
						std::cout << "You win!!!" << "\n";
						std::cout << "You just won $" << (bet * 2);
						winMoney(wallet, (bet * 2));
						goto BJend;
					}
					if (dCardTotal > cardTotal)
					{
						std::cout << "Dealer wins!" << "\n";
						goto BJend;
					}
				}
				if (dCardTotal == 21)
				{
					std::cout << "Dealer wins!" << "\n";
				}
				if (dCardTotal > 21)
				{
					std::cout << "Dealer busted! You win!" << "\n";
					std::cout << "You just won $" << bet;
					winMoney(wallet, bet);
					goto BJend;
				}

			}
		} while (playerChoice != 'H' || playerChoice != 'h' && playerChoice != 'S' || playerChoice != 's');
	} while (cardTotal < 21);

BJend:

	std::cout << "\n";
	std::cout << "\n";
	printWallet(wallet);
	std::cout << "\n";
	std::cout << "\n";
}

// shuffleCards() provided for you. DO NOT CHANGE
void shuffleCards()
{
	// Clear the original deck
	_cards.clear();

	// A container to hold all the suits by priority
	// Clubs, Diamonds, Hearts, Spades
	std::vector<std::string> suits{ "C", "D", "H", "S" };
	// A container for unshuffled cards
	std::vector<std::string> unshuffled;
	// Create all of the cards, unshuffled...
	for (int s = 0; s < suits.size(); ++s)
	{
		// Put in the Ace
		unshuffled.push_back("A" + suits[s]); // AC, AD, AH, AS
		// Put in 2 - 10
		for (int val = 2; val <= 10; ++val)
		{
			unshuffled.push_back(std::to_string(val) + suits[s]);
		}
		// Now add Jack, Queen, and King
		unshuffled.push_back("J" + suits[s]);
		unshuffled.push_back("Q" + suits[s]);
		unshuffled.push_back("K" + suits[s]);
	}

	while (unshuffled.size() > 0)
	{
		// get a random card within range
		int rc = rand() % unshuffled.size();
		std::string card = unshuffled[rc];
		// remove the card from the unshuffled deck
		unshuffled.erase(unshuffled.begin() + rc);
		// Add it to the shuffled card deck
		_cards.push_back(card);
	}

	// Now the _cards variable holds a shuffled deck of cards
}

// printCards() provided for you. DO NOT CHANGE
void printCards()
{
	// A for-loop that will loop as many times as we have cards
	for (int i = 0; i < _cards.size(); i++)
	{
		// Print a number - leave room for 2 so they line up
		std::cout << "[" << std::setw(2) << (i + 1) << "] ";
		// Print the original card representation (e.g. 10C)
		std::cout << std::setw(3) << _cards[i];
		// Print the card value (e.g. 10)
		std::cout << ": " << getCardValue(_cards[i]);
		// Print the card suit (e.g. Clubs) - go to newline
		std::cout << "-" << getSuit(_cards[i]) << "\n";
	}
}

// getCardValue() provided for you. DO NOT CHANGE
int getCardValue(std::string card)
{
	int val = 0;
	// double check to see if it is a face card
	// cards are a collection of characters (strings)
	// If it is a face card (J,Q,K) or an Ace, then the
	//	first letter (character 0) describes its value
	char face;
	if (card.length() > 0)
	{
		face = card[0];
		switch (face)
		{
		case 'A':
			val = 1;
			break;
		case 'J':
		case 'Q':
		case 'K':
			val = 10;
			break;
		default:
			// If it isn't a face card it's a number card. Default
			//	case statements catch anything not previously caught.
			// string-to-integer (stoi). Cut off the suit indicator
			// Use a substring (substr) to cut off the suit indicator
			// if the card is 10C (10 of clubs), the size is 3.if we 
			// use a substring from location 0 to size()-1 = 2 we get
			// just the 10. Then we use stoi to turn that into an int
			std::string numberOnly = card.substr(0, card.size() - 1);
			val = std::stoi(numberOnly);
			break;
		}
	}
	return val;
}

// getSuit() provided for you. DO NOT CHANGE
std::string getSuit(std::string card)
{
	// Cards are represented by a collection of characters (strings)
	// Example: 10C (10 of clubs)
	// We need to figure out what the suit is by checking only
	//	the last character in the string
	// To determine the last character's index, we use length - 1.
	std::string suit = "";
	if (card.length() > 1)
	{
		char s = card[card.length() - 1];
		// A variable to hold the suit we will return
		switch (s)
		{
		case 'C':// a case statement with no break will 'fall through' to the next
		case 'c':
			suit = "Clubs";
			break; // Execution for C or c stops here
		case 'D':
		case 'd':
			suit = "Diamonds";
			break;
		case 'H':
		case 'h':
			suit = "Hearts";
			break;
		case 'S':
		case 's':
			suit = "Spades";
			break;
		}
	}
	return suit;
}

// drawCard() provided for you. DO NOT CHANGE
std::string drawCard()
{
	std::string card = "";
	if (_cards.size() > 0)
	{
		// Grab the card at the top
		card = _cards[_cards.size() - 1];
		// remove the card off the deck
		_cards.pop_back();
	}

	// return the card to the requestor
	return card;
}

void seedRand(int seed)
{
	srand(time(0));
}

void printMoney(double money)
{
	//std::cout << std::setprecision(2) << std::fixed;
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	//std::cout << money;
}

void printWallet(double wallet)
{
	printMoney(wallet);
	std::cout << "Wallet: $" << wallet;
}

void payMoney(double & wallet, double amount)
{
	printMoney(amount);
	std::cout << "You paid $" << amount;
	wallet = wallet - amount;
}

void winMoney(double & wallet, double amount)
{
	wallet = wallet + amount;
}

int getRandomNumber(int min, int max)
{
	int randNum = 0;
	randNum = min + rand() % max;
	return randNum;
}

double placeBet(double & wallet, double & bet)
{
	std::cout << "How much do you want to bet? $";
	std::cin >> bet;
	payMoney(wallet, bet);
	return bet;
}
