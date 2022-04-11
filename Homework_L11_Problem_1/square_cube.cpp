//	===============================================================
//  Filename:		square_cube.cpp
//	Title:			mathfunctions
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    define functions
//	===============================================================

#include <cmath>
#include "myheader.h"

double square(double input)
{
    return input * input;
}
double cube(double input)
{
    return std::pow(input, 3);
}
