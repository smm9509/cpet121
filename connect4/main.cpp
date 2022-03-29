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
const unsigned int CONNECT4_WIDTH = 3;
const unsigned int CONNECT4_HEIGHT = 2;
const int CONNECT = 4;

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
//				also a reference to the board to put coins onto
//	Output:		if the move is valid, places a coin on the grid
//				also writes which player is next to the reference
//	Purpose:	allow players to make moves
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void playerPutCoin(Coins& currentPlayer, Grid& board);


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
		Grid game = Grid(CONNECT4_WIDTH, CONNECT4_HEIGHT);
		int iterations = 0;
		while(!gameFinished)
		{
			iterations++;

			cout << game.printPlain();

			playerPutCoin(currentPlayer, game);
			
			
			bool possibleTie = iterations > game.places.size() - 2;
			if(possibleTie)
			{
				bool tied = game.checkFull(winner);
				bool won = game.checkWin(winner, CONNECT);
				gameFinished = tied || won;
			} else {
				gameFinished = game.checkWin(winner, CONNECT);
			}
		}
		cout << game.printPlain();
		//add results of game to tally and print result
		switch(winner)
		{
		case x:
			tally.xWins++;
			printf("%s was the winner.\n", X_NAME);
			break;
		case o:
			tally.oWins++;
			printf("%s was the winner.\n", O_NAME);
			break;
		case space:
			tally.ties++;
			printf("The game ended in a tie.\n");
			break;
		default:
			assert(winner == x || winner == o || winner == space);
		}

		playing = PlayAgainQ();
	}
	tally.print();

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
	printf(
		"        Welcome to Connect 4\n"
		"    The goal of Connect 4 is to be the first\n"
		"player to place four coins in a row, either\n"
		"horizontally, vertically, or diagonally.\n\n"
		"%s was selected to go first.\n", 
		(firstPlayer == x) ? X_NAME : O_NAME
	);
	return firstPlayer;
}

void playerPutCoin(Coins& currentPlayer, Grid& board)
{
	int col;
	bool goodInput = false;
	int userIn;
	int userInPrev;
	bool badInput = false;
	do
	{
		printf("%s's Turn (%c) : Enter Your Move  :",
			(currentPlayer == x) ? X_NAME : O_NAME,
			currentPlayer
			);
		cin >> userIn;
		//cout << "userIn == " << userIn << endl;

		//check if move is in range
		if(userIn > 0 && userIn <= board.WIDTH)
		{
			goodInput = true;
			col = userIn - 1;
		} else {
			if(badInput)
			{
				//here, both userInPrev and userIn are, hopefully,
				//	different numbers. If not, user is insane.
				if(userIn == userInPrev)
				{
					printf("You entered the same illegal"
					" value twice (%d and %d)."
					" Either the console is broken (more likely)"
					", or you are insane (unlikely). Goodbye.\n",
					userIn, userInPrev);
					assert(userIn != userInPrev);
				}
			}
			cout << "Illegal position. Please re-enter." << endl;
			userInPrev = userIn;
			badInput = true;
		}
	} while (!goodInput); //repeat until valid column chosen

	bool coinWasPut = false;
	//go from the bottom of the board up along the selected
	//	column, looking for an empty space. Put coin there.
	for(unsigned int row = board.HEIGHT - 1; row >= 0 && row < board.HEIGHT; row--)
	{
		if(board.at(row, col) == space)
		{
			board.at(row, col) = currentPlayer;
			coinWasPut = true;
			//change the current player to the next player
			switch (currentPlayer)
			{
			case x:
				currentPlayer = o;
				break;
			case o:
				currentPlayer = x;
				break;
			
			default:
				assert(currentPlayer == x || currentPlayer == o);
				break;
			}
			break;
		}
	}

	if(!coinWasPut)
	{
		cout << "Move not available. You lost your turn." << endl;
		//change the current player to the next player
		switch (currentPlayer)
		{
		case x:
			currentPlayer = o;
			break;
		case o:
			currentPlayer = x;
			break;
		
		default:
			assert(currentPlayer == x || currentPlayer == o);
			break;
		}
	}
}