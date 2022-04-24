//	===============================================================
//  Filename:		print.cpp
//	Title:			hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-20
//  Description:    allow printing simpler strings to user
//	===============================================================

#include "hangman.h"
#include <string>
#include <iostream>

using namespace std;

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		print
//	Input: 		a string
//	Output:		print to console
//	Purpose:	display things to the user
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void print(const string& text)
{
    cout << text << endl;
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		displayWord
//	Input: 		a string with a format
//              l e * * e r   w o r d
//              depending on which letters have been guessed
//              does not need to have that spacing to work as
//              intended, although it will display differently
//	Output:		puts the word in the format
//              * * * * * 
//              _ _ _ _ _
//              in the console
//	Purpose:	display the word game state to the user
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void dispayWord(const string& word)
{
    string line1 = "";
    string line2 = "";
    line1.reserve(word.size());
    line2.reserve(word.size());
    for(int i = 0; i < word.size(); i++)
    {
        line1.push_back(word.at(i));
        if(word.at(i) != ' ')
        {
            line2.push_back('_');
        } else {
            line2.push_back(' ');
        }
    }
    print(line1);
    print(line2);
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		convertToStars
//	Input: 		a string with letters and spaces
//	Output:		a string with asterisks and spaces
//	Purpose:	obfuscate answer from player
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string& convertToStars(const string& word)
{
    string output = "";
    output.reserve(word.size());
    for(int i = 0; i < word.size(); i++)
    {
        if(word.at(i) != ' ')
        {
            output.push_back('*');
        } else {
            output.push_back(' ');
        }
    }
    return output;
}