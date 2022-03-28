//	===============================================================
//  Filename:		main.cpp
//	Title:			connect4
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-03-23
//  Description:    Project description document can be found at
//					myCourses.rit.edu > CPET.121.01 > Table of
//					Contents > Design Projects > 2022S_dp3_Connect4
//	Project:		Simulate the board game Connect4 in the console
//	===============================================================

//Template Header Comment for File:
//	===============================================================
//  Filename:		
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-03-23
//  Description:	
//	===============================================================

//Template Header Comment for Function: 
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		
	//	Input: 		
	//	Output:		
	//	Purpose:	
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Grid.h"

#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib> //rand, srand
#include <ctime> //time
using std::cin;
using std::cout;
using std::endl;
using std::string;

//some bits of text that I don't want to be "magic numbers"
const char* const O_NAME = "Player #2";
const char* const X_NAME = "Player #1";
const unsigned int CONNECT4_DEFAULT_WIDTH = 7;
const unsigned int CONNECT4_DEFAULT_HEIGHT = 6;

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		PlayAgainQ
//	Input: 		user types y or n
//	Output:		boolean, true if y
//	Purpose:	ask the user whether to continue.
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool PlayAgainQ();

struct Tally
{
	int ties, xWins, oWins;

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Constructor for Tally 
	//	Input: 		ties, number of wins for both teams
	//	Purpose:	allow initializing all variables with values
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Tally(int ties, int xWins, int oWins)
	: ties(ties), xWins(xWins), oWins(oWins) {}

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Constructor for Tally 
	//	Purpose:	initialize with zeros to start tallying
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Tally()
	: ties(0), xWins(0), oWins(0) {}

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		PrintTally
	//	Input: 		member variables only
	//	Output:		prints a statement with the tallies
	//	Purpose:	satisfy Game Tally Screen.
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	void print();
};

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		welcome
//	Output:		a welcome screen with the player that goes first
//				also returns a Coin with the player that goes first
//	Purpose:	statisfy Welcome Screen in design spec
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Coins welcome();

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		playerPutCoin
//	Input: 		player enters which column to play in
//				also a reference to a Coins var to tell which
//				player is current
//	Output:		if the move is valid, places a coin on the grid
//				also writes which player is next to the reference
//	Purpose:	allow players to make moves
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void playerPutCoin(Coins currentPlayer);


int main()
{
	//seed the random
	srand(time(NULL));

	//welcome screen
	Coins currentPlayer = welcome();


	//main loop
	bool playing = true;
	Tally tally = Tally();
	while(playing)
	{
		Coins winner;
		bool gameFinished = false;
		Grid game = Grid(CONNECT4_DEFAULT_WIDTH, CONNECT4_DEFAULT_HEIGHT);
		int iterations = 0;
		while(!gameFinished)
		{
			iterations++;

			game.printPlain();
			
			
			bool possibleTie = iterations > game.places.size() - 2;
			if(possibleTie)
			{
				gameFinished = game.checkFull(winner);
			} else {
				gameFinished = game.checkWin(winner);
			}
		}

		//add results of game to tally
		switch(winner)
		{
		case x:
			tally.xWins++;
			break;
		case o:
			tally.oWins++;
			break;
		case space:
			tally.ties++;
			break;
		default:
			assert(winner == x || winner == o || winner == space);
		}

		playing = PlayAgainQ();
	}
	tally.print();


	cout << "start meow" << endl;
	Grid myGrid(7,6);
	for(int row = 0; row < myGrid.HEIGHT; row++)
	{
		for(int col = 0; col < myGrid.WIDTH; col++)
		{
			myGrid.at(row, col) = space;
		}
	}
	cout << myGrid.printPlain() << endl;

	return 0;
}

bool PlayAgainQ()
{
	char userIn;
	cout << "Would you like to play again? [Y/N] :";
	cin >> userIn;
	cout << endl;
	userIn = tolower(userIn);
	assert(userIn == 'y' || userIn == 'n');
	return userIn == 'y';
}

void Tally::print()
{
	printf("There were %d ties. %s won %d times,"
	" and %s won %d times.\n", ties, X_NAME, xWins, 
	O_NAME, oWins);
}

Coins welcome()
{
	Coins firstPlayer;
	switch(rand() % 2)
	{
	case 0:
		firstPlayer = x;
		break;
	case 1:
		firstPlayer = o;
		break;
	default:
		assert("0" == "you messed up rand()");
	}
	printf("		Welcome to Connect 4\n"
	"	The goal of Connect 4 is to be the first\n"
	"player to place four coins in a row, either\n"
	"horizontally, vertically, or diagonally.\n\n"
	"%s was selected to go first.\n", (firstPlayer == x) ? X_NAME : O_NAME);
	return firstPlayer;
}
