//	===============================================================
//  Filename:		userin.cpp
//  Title:          hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-21
//  Description:	define a function for getting a character input
//	===============================================================

#include "hangman.h"

#include <iostream>
#include <string>

using namespace std;



//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		userInput
//	Input: 		user types a line of text
//	Output:		returns the first character from that line
//	Purpose:	get user guess
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char userInput()
{
	//cin.ignore(); //this function doesn't help, I think.
	string temp;
	getline(cin, temp);
	return temp.c_str()[0];
}