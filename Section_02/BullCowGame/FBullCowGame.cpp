#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }


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

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}


bool FBullCowGame::IsIsogram(std::string)
{
	return false;
}
