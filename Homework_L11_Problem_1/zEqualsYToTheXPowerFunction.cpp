
//	===============================================================
//  Filename:		zEqualsYToTheXPowerFunction.cpp
//	Title:			mathfunctions
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    define function
//	===============================================================

#include "myheader.h"
#include <cassert>

//local function to allow similar functionality to fmod
//, but without #include <cmath>
double dmod(double x, double y) {
	return x - (int)(x/y) * y;
}

// z = y ^ x, return z
double zEqualsYToTheXPower(double x, double y)
{
	//all examples I could find online use either #include <cmath> 
	//or #include <math.h> to implement finding the power when the 
	//exponent is not an integer. The assignment prohibits the use
	//of these libraries.
	assert(dmod(x, 1) == 0.0); //x must be perfectly divisible by 1
	//, or else the return value will not be accurate.

	double base = y;
	int power  	= x;

	if(power == 0)
	{
		return 1;
	}

	bool negativePower;
	if (power < 0)
	{
		power*= -1;
		negativePower = true;
	} else
	{
		negativePower = false;
	}
	
	if (power > 0)
	{
		for(power; power > 1; power--)
		{
			base *= y;
		}

		if(negativePower)
		{
			return 1.0/base;
		}
		return base;

	} //else
	{
		//something's not right
		return (-x)/0.0;
	}

}