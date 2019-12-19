#include "FBullCowGame.h"

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


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

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; //TODO make actual error
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

	for (int32 MHWChar = 0; MHWChar< HiddenWordLength; MHWChar++) 
	{
		//copare letters agains the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				if (MHWChar == GChar) 
				{ //if they are in the same place
					BullCowCount.Bulls++; //increment Bulls
				}
				else 
				{
					BullCowCount.Cows++; // Must be cow
				}
			}
		}
	}

	return BullCowCount;
}

