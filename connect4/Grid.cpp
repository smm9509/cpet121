//	===============================================================
//  Filename:		Grid.cpp
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-03-23
//  Description:    Define a class that stores a Connect4 Grid
//	===============================================================

#include "Grid.h"

Grid::Grid(const size_t WIDTH,  const size_t HEIGHT) 
: WIDTH(WIDTH), HEIGHT(HEIGHT) 
{
	places = std::vector<char16_t>(WIDTH*HEIGHT);
};

Grid::Grid(const Grid& obj)
: WIDTH(obj.WIDTH), HEIGHT(obj.HEIGHT)
{
	places = std::vector<char16_t>(obj.places);
}