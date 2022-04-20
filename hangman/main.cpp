//	===============================================================
//  Filename:		main.cpp
//	Title:			hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-18
//  Description:    define the main function
//	===============================================================

#include "hangman.h"
#include <iostream>

int main()
{
    printf(replaceAll("I have 100 cats and 1000 dogs and"
    " 100100100 nyans", "100", "%d").c_str(), 100, 100, 100, 100, 100);

    return 0;
}