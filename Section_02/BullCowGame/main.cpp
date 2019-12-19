/*
This is console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate new game



//the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return	0;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	// loop for the number of turns asking for guesses, change to while loop
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make check for valid guesses
		
		//TODO submit valid guess to the game
		//Print number of bulls and cows

		std::cout << "Your guess was: " << Guess <<std::endl;

		std::cout << std::endl;
	}
	// TODO summarize game
}

void PrintIntro()
{
	//introduce the game
	constexpr int32 WORD_LENGHT = 5;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

FText GetGuess() 
{
	int32 MyCurrentTry = BCGame.GetCurrentTry();

	//get the guess from the player
	std::cout << "Try " << MyCurrentTry <<". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response = "";
		std::getline(std::cin, Response);
		return (Response[0] == 'y') || (Response[0] == 'Y');
	
}
