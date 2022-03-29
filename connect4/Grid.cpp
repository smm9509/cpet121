//	===============================================================
//  Filename:		Grid.cpp
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-03-23
//  Description:    Define a class that stores a Connect4 Grid
//	===============================================================

#include "Grid.h"
#include <cassert>

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

Grid::Grid(const Grid& obj)
: WIDTH(obj.WIDTH), HEIGHT(obj.HEIGHT)
{
	places = vector<Coins>(obj.places);
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

bool Grid::checkWin(Coins& winner, int winLength) const
{
	printf("It is currently assumed impossible to win.\n");
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