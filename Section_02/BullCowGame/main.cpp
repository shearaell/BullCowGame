#include <iostream>

#include <string>

using namespace std;

int main()
{
	//introduce the game
	constexpr int WORD_LENGHT = 5;
	cout <<"Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGHT;
	cout <<	" letter isogram I'm thinking of?\n";
	cout << endl;

	//get the guess from the player
	cout << "Enter your guess: ";
	string Guess = "";
	cin >> Guess;

	//repeat the guess back to them
	cout << "Your guess was: " << Guess;
	cout << endl;

	//get the guess from the player
	cout << "Enter your guess: ";
	cin >> Guess;

	//repeat the guess back to them
	cout << "Your guess was: " << Guess;
	cout << endl;

	//get the guess from the player
	cout << "Enter your guess: ";
	cin >> Guess;

	//repeat the guess back to them
	cout << "Your guess was: " << Guess;
	cout << endl;

	return	0;
}