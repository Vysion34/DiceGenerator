// DiceGenerator.cpp : Defines the entry point for the console application.

/* Dean Hartfield

8-8-2015

Module 05 Coding Project #1 - Dice Generator

This program simulates rolling 5 dice.
*/


#include "stdafx.h"
#include <iostream>
#include <random>


/* Dice class for rolling the die and storing the value of the roll.
   This class uses a Mersenne Twister pseudo-random number generator
   seeded with a random_device random number generator. Thus each
   instance of the class will use its own Mersenne Twister PRNG.
   A uniform distribution is also used to ensure the randomness is
   distributed evenly on the interval.
*/
class Dice {
public:
	Dice();
	int getValue();
	void Roll();
private:
	std::random_device rd;
	std::mt19937 mersenneTwister{ rd() };
	std::uniform_int_distribution<int> uniformDist{ 1, 6 };
	int Value;
};

Dice::Dice()
{
	Value = 0;
}

int Dice::getValue()
{
	return Value;
}

void Dice::Roll()
{
	// Feed the Mersenne Twister PRNG into the uniform distribution and assign to the value field
	Value = uniformDist(mersenneTwister);
}

static void RollDice()
{
	Dice* dice = new Dice[5]{};  // Dice array
	char rollAgain = 'N';

	// do..while loop to ask if the user wants to roll again
	do {
		system("cls");  // Clear the console before each roll

		// Iterate through the dice array and roll each one and print out its value
		for (int i = 0; i < 5; i++) {
			dice[i].Roll();
			std::cout << "Die " << (i + 1) << " = " << dice[i].getValue() << std::endl;
		}

		// Ask the user if they want to roll again
		std::cout << std::endl << "Roll again? (Y for Yes, N for No): ";
		std::cin >> rollAgain;
	} while ((rollAgain == 'Y') || (rollAgain == 'y'));
	
	delete[] dice;
}

int main(int argc, _TCHAR* argv[])
{
	RollDice();
	std::cout << std::endl;
	system("pause");
	return 0;
}
