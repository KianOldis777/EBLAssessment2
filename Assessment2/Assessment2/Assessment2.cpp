// Assessment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MyPlayer {      
public:             
	int myGuesses; // Uses the class to keep track of guesses
};

int replay(int a)
{
	cout << "\nPlay again? (0 = Yes, 1 = No)\n"; // Asks the player if they want to play again
	cin >> a;
	return a;
}

int main()
{

	int retry = 0;

	do
	{
		int difficulty = 0;
		int diff[3] = { 50, 100, 150 };
		cout << "What difficulty would you like? (0 = Easy 50, 1 = Normal 100, 2 = Hard 150)\n";
		cin >> difficulty; //Decides on the difficulty of the game
		

		int number1, number2, guesses1, guesses2, attempts = 0;

		srand(time(0));
		number1 = rand() % diff[difficulty] + 1; // RNG between values dependant on difficulty
		number2 = rand() % diff[difficulty] + 1;

		cout << "Guess The Number!\n\n";

		do
		{


			MyPlayer  player1;
			player1.myGuesses = 0;

			MyPlayer  player2; //Keeping track of guesses
			player2.myGuesses = 0;

			cout << "Player 1, Take A Guess : ";
			cin >> guesses1;
			attempts++; // Adds to the amount of guesses each guess
			player1.myGuesses = attempts;

			if (guesses1 > number1)
			{
				cout << "Too high!\n\n"; // They gussed a number that's higher than the answer
			}
			else if (guesses1 < number1)
			{
				cout << "Too low!\n\n"; // They gussed a number that's lower than the answer
			}
			else
			{
				cout << "\nGood Job Player 1, You Win! It took you " << player1.myGuesses << " guesses!\n"; // The guess isn't too high or low, it's right!
			}

			cout << "Player 2, Take A Guess : ";
			cin >> guesses2;
			attempts++; // Adds to the amount of guesses each guess
			player2.myGuesses = attempts;

			if (guesses2 > number2)
			{
				cout << "Too high!\n\n"; // They gussed a number that's higher than the answer
			}
			else if (guesses2 < number2)
			{
				cout << "Too low!\n\n"; // They gussed a number that's lower than the answer
			}
			else
			{
				cout << "\nGood Job Player 2, You Win! It took you " << player2.myGuesses << " guesses!\n"; // The guess isn't too high or low, it's right!
			}




		} while (guesses1 != number1 && guesses2 != number1);
		retry = replay(retry);
	} while (retry == 0);
}