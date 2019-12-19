#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); // to do make a more rich value.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const; // to make more rich return value
	//counts bulls and cows; and increases try # assuming valid guess
	FBullCowCount SubmitGuess(FString);

//please try ingnore and focus on int32erface above 
private:
	//see constructor for initialiation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};