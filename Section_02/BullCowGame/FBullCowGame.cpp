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

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}


//Receives valid guess, incriments turn and returns turns
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	//loop trough all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i< HiddenWordLength; i++) {
		//copare letters agains the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			//if they match then
			if (Guess[i] == MyHiddenWord[i]){
				if (i == j) { //if they are in the same place
					BullCowCount.Bulls++; //increment Bulls
				}
				else {
					BullCowCount.Cows++; // Must be cow
				}
			}
		}
	}

	return BullCowCount;
}