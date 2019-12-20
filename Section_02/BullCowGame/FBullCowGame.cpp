#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }



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
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess) ) //if the gues is not the isogram, return an error
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{//if the guess lenght is wrong, return an error
		return EGuessStatus::Not_Lowercase;

	} else  if (Guess.length() != GetHiddenWordLength() )
	{
		return EGuessStatus::Wrong_Length;
	} else 
	{   //else return ok
		return EGuessStatus::OK;
	}
}


//Receives valid guess, incriments turn and returns turns
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	//loop trough all letters in the hidden word
	int32 WordLength = MyHiddenWord.length(); //assuming same lenght a guess

	for (int32 MHWChar = 0; MHWChar< WordLength; MHWChar++) 
	{
		//copare letters agains the hidden guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
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
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isograms

	//loop trought all letters
	// if the letter is in dictionary 
	//We do not have isogram
	//Add letter to the map
	return true;
}

