#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); // to do make a more rich value.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); // to make more rich return value
	// provide a method for counting bulls and cows and increasing try

//please try ingnore and focus on int32erface above 
private:
	//see constructor for initialiation
	int32 MyCurrentTry;
	int32 MyMaxTries;
};