#include <iostream>

#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuessPrintBack();
bool AskToPlayAgain();



//the entry point for our application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return	0;
}

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuessPrintBack();
		//repeat the guess back to them
		cout << "Your guess was: " << Guess <<endl;

		cout << endl;
	}
}

void PrintIntro()
{
	//introduce the game
	constexpr int WORD_LENGHT = 5;
	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGHT;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

string GetGuessPrintBack() 
{
	//get the guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response = "";
		getline(cin, Response);
		return (Response[0] == 'y') || (Response[0] == 'Y');
	
}
