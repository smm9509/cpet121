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


string Grid::print(
	const std::string& TOP_LEFT/* = " "*/, 
	const std::string& TOP_LINE/* = " "*/,
	const std::string& TOP_WYE/* = " "*/, 
	const std::string& TOP_RIGHT/* = " \n"*/, 

	const std::string& LEFT_LINE/* = " "*/, 
	const std::string& RIGHT_LINE/* = " \n"*/,
	const std::string& X_SUB/* = "X"*/,
	const std::string& O_SUB/* = "O"*/,
	const std::string& EMPTY_SUB/* = "_"*/,

	const std::string& LEFT_WYE/* = " "*/, 
	const std::string& RIGHT_WYE/* = " \n"*/, 
	const std::string& CROSS/* = " "*/, 
	const std::string& MID_VERT/* = " "*/,	
	const std::string& MID_HORZ/* = " "*/,

	const std::string& BOTTOM_LEFT/* = " "*/, 
	const std::string& BOTTOM_LINE/* = " "*/,
	const std::string& BOTTOM_WYE/* = " "*/, 
	const std::string& BOTTOM_RIGHT/* = " \n"*/
)
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
		case empty:
			p.append(EMPTY_SUB);
			break;
		default:
			exit(2);
		}
	};

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