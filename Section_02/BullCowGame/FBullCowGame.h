#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // to do make a more rich value.
	int GetMaxTries() const;
	int GentCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); // to make more rich return value

//please try ingnore and focus on interface above 
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram(std::string);
};