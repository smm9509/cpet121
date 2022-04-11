//	===============================================================
//  Filename:		main.cpp
//	Title:			mathfunctions
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    use multiple .cpp files for abs, square, cube
//	===============================================================

#include "L11Homework2.h"

using std::to_string;

int main()
{
	double squared;
	double cubed;
	double absoluted;
	double z;

	calculate(
		squared, cubed, absoluted, z, 
		inputFunction("Enter a number to square: "), 
		inputFunction("Enter a number to cube:"), 
		inputFunction("Enter a number to absolute value"), 
		inputFunction("For z = y ^ x, enter x:"),
		inputFunction("For z = y ^ x, enter y:")
	);

	outputFunction("the result of squaring is:");
	outputFunction(to_string(squared));
	outputFunction("the result of cubing is:");
	outputFunction(to_string(cubed));
	outputFunction("the result of absolute value is:");
	outputFunction(to_string(absoluted));
	outputFunction("z in z = y ^ x is:");
	outputFunction(to_string(z));
	
	return 0;
}