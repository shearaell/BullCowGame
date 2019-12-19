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
FText GetValidGuess();
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
	//std::cout << MaxTries << std::endl;

	// loop for the number of turns asking for guesses, change to while loop
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetValidGuess(); // TODO make check for valid guesses
		




		//TODO submit valid guess to the game and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls= " << BullCowCount.Bulls;
		std::cout << " Cows= " << BullCowCount.Cows;
		std::cout << std::endl;

		std::cout << "Your guess was: " << Guess << "\n\n";
	}
	// TODO summarize game
}

//introduce the game
void PrintIntro()
{

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

//loop continue until get right guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		//get the guess from the player
		int32 MyCurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << MyCurrentTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lower caseletters. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters. \n";
			break;
		default:
			break; //assuming the gues is valid
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK ); //kepp looping until no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response = "";
		std::getline(std::cin, Response);
		return (Response[0] == 'y') || (Response[0] == 'Y');
	
}
