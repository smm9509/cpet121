//	===============================================================
//  Filename:		inputFunction.cpp
//	Title:			mathfunctions
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    declare function
//	===============================================================


#include <iostream>
#include "L11Homework2.h"

using namespace std;

double inputFunction(const string& query = "")
{
	outputFunction(query);
	double temp;
	cin >> temp;
	return temp;
}
