//	===============================================================
//	Title: Grid.h
//	Course: CPET.121.01/05-06 - Computational Prob Solving I
//	Developer: smm9509@rit.edu
//	Date: 2022-03-23
//	Description: Header for Grid.cpp
//	===============================================================

#pragma once
#include <vector>
#include <string>

enum Coins : char16_t {x = 'X', o = 'O', space = ' '};

struct Grid
{
public:
	const size_t WIDTH;
	const size_t HEIGHT;
	std::vector<Coins> places;

	//not allowed to make a default board, must specify size
	Grid() = delete;

	//main constructor
	//requires grid height and width;
	Grid(const size_t WIDTH,  const size_t HEIGHT);

	//copy constructor
	//performs a deep copy when copying
	Grid(const Grid& OBJ);

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		checkWin
	//	Input: 		any Coins variable
	//				, and the connect length required to win
	//	Output:		returns true if someone has won;
	//				if yes, writes winning side to winner.
	//				When return value is true, winner is garunteed
	//				to be overwritten (useful if unitnitialized).
	//	Purpose:	allow stopping the game when won
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool checkWin(Coins& winner, int winLength = 4) const;

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		checkFull
	//	Input: 		any Coins variable
	//	Output:		returns true if the grid is full and no more 
		//				plays can be made
		//				writes empty to winner if it's full
		//				PLEASE run checkWin afterward to check if
		//				the last move was a winning move.
		//			When return value is true, winningSide is 
		//				garunteed to be overwritten with Coins::space
		//				(useful if unitnitialized).
	//	Purpose:	stop when tie
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool checkFull(Coins& winningSide) const;

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		Grid::at
	//	Input: 		row and column on the Grid
	//	Output:		a reference to the coin at the input location
	//	Purpose:	reading (const version) or writing coins
	//				on the grid
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Coins& at(int row, int column);
	const Coins& at(int row, int column) const;

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		Grid::print
	//	Input: 		characters for lines and fill
	//	Output:		string with the game grid 
	//	Purpose:	display the bulk state of the game to the user
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string print(
		const std::string& NUMBERLINE_SEPARATOR_LEFT = " ",
		const std::string& NUMBERLINE_SEPARATOR_MID = " ",
		const std::string& NUMBERLINE_SEPARATOR_RIGHT = " \n",

		const std::string& TOP_LEFT = " ", 
		const std::string& TOP_LINE = " ",
		const std::string& TOP_WYE = " ", 
		const std::string& TOP_RIGHT = " \n", 

		const std::string& LEFT_LINE = " ", 
		const std::string& RIGHT_LINE = " \n",
		const std::string& X_SUB = "X", 
		const std::string& O_SUB = "O",
		const std::string& SPACE_SUB = "_",

		const std::string& LEFT_WYE = " ", 
		const std::string& RIGHT_WYE = " \n", 
		const std::string& CROSS = " ", 
		const std::string& MID_VERT = " ",	
		const std::string& MID_HORZ = " ",

		const std::string& BOTTOM_LEFT = " ", 
		const std::string& BOTTOM_LINE = " ",
		const std::string& BOTTOM_WYE = " ", 
		const std::string& BOTTOM_RIGHT = " \n"
	) const;

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		Grid::printPlain
	//	Input: 		characters for lines and fill
	//	Output:		string with the game grid 
	//	Purpose:	run Grid::print with ASCII characters
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	std::string printPlain(
		const std::string& NUMBERLINE_SEPARATOR_LEFT = "   ",
		const std::string& NUMBERLINE_SEPARATOR_MID = "   ",
		const std::string& NUMBERLINE_SEPARATOR_RIGHT = "  \n",

		const std::string& TOP_LEFT = "  ", 
		const std::string& TOP_LINE = "   ",
		const std::string& TOP_WYE = " ", 
		const std::string& TOP_RIGHT = " \n", 

		const std::string& LEFT_LINE = " |", 
		const std::string& RIGHT_LINE = "|\n",
		const std::string& X_SUB = " X ", 
		const std::string& O_SUB = " O ",
		const std::string& SPACE_SUB = "   ",

		const std::string& LEFT_WYE = " +", 
		const std::string& RIGHT_WYE = "+\n", 
		const std::string& CROSS = "+", 
		const std::string& MID_VERT = "|",	
		const std::string& MID_HORZ = "---",

		const std::string& BOTTOM_LEFT = " +", 
		const std::string& BOTTOM_LINE = "---",
		const std::string& BOTTOM_WYE = "+", 
		const std::string& BOTTOM_RIGHT = "+\n"
	) const;
};
