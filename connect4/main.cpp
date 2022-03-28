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
using std::cout;
using std::endl;

int main()
{
	cout << "start nya" << endl;
	Grid myGrid(7,6);
	for(int row = 0; row < myGrid.HEIGHT; row++)
	{
		for(int col = 0; col < myGrid.WIDTH; col++)
		{
			myGrid.at(row, col) = space;
		}
	}
	cout << myGrid.print() << endl;

	return 0;
}