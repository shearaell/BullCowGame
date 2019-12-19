#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


bool FBullCowGame::IsGameWon() const
{
	return false;
}



FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset() 
{
	constexpr int MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}


//Receives valid guess, incriments turn and returns turns
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//increment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCout;

	//loop trough all letters in the guess
		//copare letters agains the hidden word


	return BullCowCount();
}