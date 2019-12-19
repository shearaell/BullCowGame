#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset(); // to do make a more rich value.
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); // to make more rich return value
	// provide a method for counting bulls and cows and increasing try

//please try ingnore and focus on interface above 
private:
	//see constructor for initialiation
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(std::string);
};