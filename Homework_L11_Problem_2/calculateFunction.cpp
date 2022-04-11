//	===============================================================
//  Filename:		calculateFunction.cpp
//	Title:			mathfunctions
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    define function
//	===============================================================

#include "L11Homework2.h"

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		calculate
//	Input: 		inSquare, inCube, inAbs, inEqnX, inEqnY
//                  these values are passed as inputs to  
//                  other functions
//	Output:		outSquare, outCube, outAbs, outEqnZ
//                  these references are written to to output
//                  the return values of other functions
//	Purpose:	combine everything into one function
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void calculate(double& outSquare, double& outCube, double& outAbs, 
double& outEqnZ, double inSquare, double inCube, double inAbs, 
double inEqnX, double inEqnY)
{
    outSquare = square(inSquare);
    outCube = cube(inCube);
    outAbs = myAbsoluteVal(inAbs);
    outEqnZ = zEqualsYToTheXPower(inEqnX, inEqnY);
}