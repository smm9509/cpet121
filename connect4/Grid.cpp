//	===============================================================
//  Filename:		Grid.cpp
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-03-23
//  Description:    Define a class that stores a Connect4 Grid
//	===============================================================

#include "Grid.h"
#include <cassert>
#include <cstdlib>

using namespace std;

Grid::Grid(const size_t WIDTH,  const size_t HEIGHT) 
: WIDTH(WIDTH), HEIGHT(HEIGHT) 
{
	assert(WIDTH > 0 && HEIGHT > 0);
	places = vector<Coins>(WIDTH*HEIGHT);
	//fill grid with empty spaces (initialize)
	for(int row = 0; row < HEIGHT; row++)
	{
		for(int col = 0; col < WIDTH; col++)
		{
			at(row, col) = space;
			//printf("wrote [%c] to (%d, %d)\n", space, col, row);
		}
	}

};

Grid::Grid(const Grid& OBJ)
: WIDTH(OBJ.WIDTH), HEIGHT(OBJ.HEIGHT)
{
	places = vector<Coins>(OBJ.places);
}

Coins& Grid::at(int row, int column)
{
	return places.at(column + row*WIDTH);
}
const Coins& Grid::at(int row, int column) const
{
	return places.at(column + row*WIDTH);
}


string Grid::print(
	const std::string& NUMBERLINE_SEPARATOR_LEFT/* = " "*/,
	const std::string& NUMBERLINE_SEPARATOR_MID/* = " "*/,
	const std::string& NUMBERLINE_SEPARATOR_RIGHT/* = " \n"*/,

	const std::string& TOP_LEFT/* = " "*/, 
	const std::string& TOP_LINE/* = " "*/,
	const std::string& TOP_WYE/* = " "*/, 
	const std::string& TOP_RIGHT/* = " \n"*/, 

	const std::string& LEFT_LINE/* = " "*/, 
	const std::string& RIGHT_LINE/* = " \n"*/,
	const std::string& X_SUB/* = "X"*/,
	const std::string& O_SUB/* = "O"*/,
	const std::string& SPACE_SUB/* = "_"*/,

	const std::string& LEFT_WYE/* = " "*/, 
	const std::string& RIGHT_WYE/* = " \n"*/, 
	const std::string& CROSS/* = " "*/, 
	const std::string& MID_VERT/* = " "*/,	
	const std::string& MID_HORZ/* = " "*/,

	const std::string& BOTTOM_LEFT/* = " "*/, 
	const std::string& BOTTOM_LINE/* = " "*/,
	const std::string& BOTTOM_WYE/* = " "*/, 
	const std::string& BOTTOM_RIGHT/* = " \n"*/
) const
{
	string p = "";
	p.reserve(WIDTH*3*HEIGHT*3);

	//a local lambda to help with "_SUB" outputs
	auto slot = [&](int row, int col) 
	{ 
		switch(at(row, col))
		{
		case x:
			p.append(X_SUB);
			break;
		case o:
			p.append(O_SUB);
			break;
		case space:
			p.append(SPACE_SUB);
			break;
		default:
			exit(2);
		}
	};

	//number line
	{
		//start line
		p.append(NUMBERLINE_SEPARATOR_LEFT);
		p.append("1");
		//fill
		for(int i = 1; i < WIDTH; i++)
		{
			p.append(NUMBERLINE_SEPARATOR_MID);
			p.append(std::to_string(i+1));
		}
		//end line
		{
			p.append(NUMBERLINE_SEPARATOR_RIGHT);
		}
	}

	//top
	{
		//start line
		p.append(TOP_LEFT);
		p.append(TOP_LINE);
		//fill
		for(int i = 1; i < WIDTH; i++)
		{
			p.append(TOP_WYE);
			p.append(TOP_LINE);
		}
		//end line
		p.append(TOP_RIGHT);
		//start body
		{
			//start line
			p.append(LEFT_LINE);
			slot(0,0);
			//fill line
			for(int col = 1; col < WIDTH; col++)
			{
				p.append(MID_VERT);
				slot(0,col);
			}
			//end line
			p.append(RIGHT_LINE);
		}
	}

	//middle
	{
		for(int row = 1; row < HEIGHT; row++)
		{
			//start line
			p.append(LEFT_WYE);
			p.append(MID_HORZ);
			//fill line
			for(int col = 1; col < WIDTH; col++)
			{
				p.append(CROSS);
				p.append(MID_HORZ);
			}
			//end line
			p.append(RIGHT_WYE);
			
			//start line
			p.append(LEFT_LINE);
			slot(row, 0);
			//fill line
			for(int col = 1; col < WIDTH; col++)
			{
				p.append(MID_VERT);
				slot(row, col);
			}
			//end line
			p.append(RIGHT_LINE);
		}
	}

	//bottom
	{
		//start line
		p.append(BOTTOM_LEFT);
		p.append(BOTTOM_LINE);
		//fill
		for(int i = 1; i < WIDTH; i++)
		{
			p.append(BOTTOM_WYE);
			p.append(BOTTOM_LINE);
		}
		//end line
		p.append(BOTTOM_RIGHT);
	}

	return string(p);
}


string Grid::printPlain(
	const std::string& NUMBERLINE_SEPARATOR_LEFT,
	const std::string& NUMBERLINE_SEPARATOR_MID,
	const std::string& NUMBERLINE_SEPARATOR_RIGHT,

	const std::string& TOP_LEFT, 
	const std::string& TOP_LINE,
	const std::string& TOP_WYE, 
	const std::string& TOP_RIGHT, 

	const std::string& LEFT_LINE, 
	const std::string& RIGHT_LINE,
	const std::string& X_SUB,
	const std::string& O_SUB,
	const std::string& SPACE_SUB,

	const std::string& LEFT_WYE, 
	const std::string& RIGHT_WYE, 
	const std::string& CROSS, 
	const std::string& MID_VERT,	
	const std::string& MID_HORZ,

	const std::string& BOTTOM_LEFT, 
	const std::string& BOTTOM_LINE,
	const std::string& BOTTOM_WYE, 
	const std::string& BOTTOM_RIGHT
) const
{
	return print(
	NUMBERLINE_SEPARATOR_LEFT,
	NUMBERLINE_SEPARATOR_MID,
	NUMBERLINE_SEPARATOR_RIGHT,

	TOP_LEFT, 
	TOP_LINE,
	TOP_WYE, 
	TOP_RIGHT, 

	LEFT_LINE, 
	RIGHT_LINE,
	X_SUB,
	O_SUB,
	SPACE_SUB,

	LEFT_WYE, 
	RIGHT_WYE, 
	CROSS, 
	MID_VERT,	
	MID_HORZ,

	BOTTOM_LEFT, 
	BOTTOM_LINE,
	BOTTOM_WYE, 
	BOTTOM_RIGHT
	);
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		checkVectWin
//	Input: 		a grid, row&col to start from, and a direction
//				to go along (must be vertical horizontal, or
//				diagonal. Length of vector corresponds to
//				winLength)
//				also a Coins variable, will be written to if
//				there is a winner
//	Output:		true if the selected position is part of a 
//				winning play
//	Purpose:	"private" local function to make checkWin easier.
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool checkVectWin(const Grid& GRID, 
	const unsigned int ROW, const unsigned int COL,
	int deltaX, int deltaY, Coins& winner
)
{
	assert(abs(deltaX) == abs(deltaY) || (deltaY == 0 xor deltaX == 0));
	//either it's diagonal or it's vertical or horizontal. 
	//Non-perfect diagonals and vector that goes nowhere not allowed.

	assert(ROW >= 0 && ROW < GRID.HEIGHT);
	assert(COL >= 0 && COL < GRID.WIDTH);
	assert(ROW + deltaY >= 0 && ROW + deltaY < GRID.HEIGHT);
	assert(COL + deltaX >= 0 && COL + deltaX < GRID.WIDTH);
	//check that it's in range

	//set iterator to 0, 1, or -1
	signed int xIter = deltaX == 0 ? 0 : deltaX/abs(deltaX);
	signed int yIter = deltaY == 0 ? 0 : deltaY/abs(deltaY);
	//find winLength, instead of taking it as a parameter and asserting
	signed int length = 1 + (deltaX ? abs(deltaX) : abs(deltaY)); //see first assertion

	unsigned int row = ROW;
	unsigned int col = COL;

	//first iteration (i = 0) needs to be different
	assert(
		(row >= 0 && row < GRID.HEIGHT) 
		&&
		(col >= 0 && col < GRID.WIDTH)
	);
	Coins possibleWinner = GRID.at(row, col);
	if(possibleWinner == space)
	{
		return false;
	}
	row += yIter;
	col += xIter;

	for(int i = 1; i < length; i++)
	{
		assert(
			(row >= 0 && row < GRID.HEIGHT) 
			&&
			(col >= 0 && col < GRID.WIDTH)
		);
		if(possibleWinner != GRID.at(row, col))
		{
			return false;
		}
		row += yIter;
		col += xIter;
	}
	//all coins under the vector are now equal to possibleWinner

	winner = possibleWinner;
	return true;
}

bool Grid::checkWin(Coins& winner, const int WIN_LENGTH) const
{
	// need to check in staggered patterns ...
	// example with horizontal win
	// 	1234567
	// 	====
	//	 ====
	//	  ====
	//	   ====
	//repeat the above pattern on every row

	for(int row = 0; row < HEIGHT; row++)
	{
		for(int col = 0; col <= WIDTH-WIN_LENGTH; col++)
		{
			if(checkVectWin(
				*this, row, col, 
				(WIN_LENGTH-1), 0, //going horizontal
				winner)
			)
			{
				return true;
			}
		}
	}

	//vertical:
	//	1 |
	//	2 ||
	//	3 |||
	//	4 |||
	//	5  ||
	//	6   |
	//repeat the above pattern on every column

	for(int row = 0; row <= HEIGHT-WIN_LENGTH; row++)
	{
		for(int col = 0; col < WIDTH; col++)
		{
			if(checkVectWin(
				*this, row, col, 
				0, (WIN_LENGTH-1), //going vertical
				winner)
			)
			{
				return true;
			}
		}
	}

	// for diagonals, crop the range of the whole array (6x7)
	// by winLength-1 (3x4), then shoot vectors from each point
	// in the cropped zone.
	// 	  1 2 3 4 5 6 7
	//	1*⭨*⭨*⭨*⭨ 
 	//	2*⭨*⭨*⭨*⭨ ⭨ 
 	//	3*⭨*⭨*⭨*⭨ ⭨ ⭨ 
	//	4   ⭨ ⭨ ⭨ ⭨ ⭨ ⭨
	//	5     ⭨ ⭨ ⭨ ⭨ ⭨
	//	6       ⭨ ⭨ ⭨ ⭨

	for(int row = 0; row <= HEIGHT-WIN_LENGTH; row++)
	{
		for(int col = 0; col <= WIDTH-WIN_LENGTH; col++)
		{
			if(checkVectWin(
				*this, row, col, 
				(WIN_LENGTH-1), (WIN_LENGTH-1), //going diagonal down-left
				winner)
			)
			{
				return true;
			}
		}
	}
	for(int row = 0; row <= HEIGHT-WIN_LENGTH; row++)
	{
		for(int col = WIDTH-1; col >= WIN_LENGTH-1; col--)
		{
			if(checkVectWin(
				*this, row, col, 
				-(WIN_LENGTH-1), (WIN_LENGTH-1), //going diagonal down-right
				winner)
			)
			{
				return true;
			}
		}
	}



	return false;
}

bool Grid::checkFull(Coins& winningSide) const
{
	int row = 0;
	for(int col = 0; col < WIDTH; col++)
	{
		if(at(row, col) == space)
		{
			return false;
		}
	}
	winningSide = space;
	return true;
}