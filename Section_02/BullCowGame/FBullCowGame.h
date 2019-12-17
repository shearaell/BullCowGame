#pragma once

class FBullCowsGame {
public:
	void Reset(); // to do make a more rich value.
	int GetMaxTries();
	int GentCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(); // to make more rich return value

//please try ingnore and focus on interface above 
private:
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(string);
};