//	===============================================================
//	Title: Grid.h
//	Course: CPET.121.01/05-06 - Computational Prob Solving I
//	Developer: smm9509@rit.edu
//	Date: 2022-03-23
//	Description: Header for Grid.cpp
//	===============================================================

#pragma once
#include <vector>

enum Coins : char16_t {X = 'X', O = 'O', empty = ' '};

struct Grid
{
public:
	const size_t WIDTH;
	const size_t HEIGHT;
	std::vector<char16_t> places;

	//not allowed to make a default board, must specify size
	Grid() = delete;

	//main constructor
	//requires grid height and width;
	//standard Connect4 grid: 6 tall 7 wide
	Grid(const size_t WIDTH,  const size_t HEIGHT);

	//copy constructor
	//performs a deep copy when copying
	Grid(const Grid& obj);

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		checkWin
	//	Input: 		any Coins variable
	//				, and the connect length required to win
	//	Output:		returns true if someone has won;
	//				if yes, writes winning side to winner
	//	Purpose:	allow stopping the game when won
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	bool checkWin(Coins& winner, int winLength = 4);

	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//	Name: 		Grid::at
	//	Input: 		row and column on the Grid
	//	Output:		a reference to the coin at the input location
	//	Purpose:	reading or writing coins on the grid
	//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	Coins& at(int row, int column);
};
