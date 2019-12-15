#include <iostream>

#include <string>

using namespace std;

void PrintIntro();
string GetGuessPrintBack();



//the entry point for our application
int main()
{
	PrintIntro();
	
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		GetGuessPrintBack();
		cout << endl;
	}
	
	cout << endl;


	return	0;
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
	//repeat the guess back to them
	cout << "Your guess was: " << Guess;

	cout << endl;
	return Guess;
}