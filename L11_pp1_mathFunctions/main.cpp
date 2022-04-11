//	===============================================================
//  Filename:		main.cpp
//	Title:			mathfunctions
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    use multiple .cpp files for abs, square, cube
//	===============================================================

#include <cmath>
#include <iostream>
#include <string>
#include "myHeader.h"

using namespace std;

void print(const string& output)
{
    cout << output << endl;
}

double inputNum(const string& query = "")
{
    print(query);
    double temp;
    cin >> temp;
    return temp;
}

int main()
{
    print("square: " + to_string(square(inputNum("number to square:"))));
    print("cube: " + to_string(cube(inputNum("number to cube:"))));
    print("abs: " + to_string(myAbsoluteVal(inputNum("number to abs:"))));

    return 0;
}