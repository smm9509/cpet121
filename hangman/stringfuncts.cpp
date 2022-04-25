//	===============================================================
//  Filename:		stringfuncts.cpp
//	Title:			hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-20
//  Description:    provide some functions for working with the 
//                  strings representing user progress/success
//	===============================================================

#include "hangman.h"
#include <string>
#include <algorithm>
//#include <regex>

using namespace std;


//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		replaceALL
//	Input: 		text body, text to find, replace found text with
//	Output:		a string similar to body with text replaced the
//              normal way
//	Purpose:	find and replace
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string replaceAll(
    const string& text, 
    const string& find, 
    const string& replace,
    int& numReplaced // = 0
)
{
    string str = text; //copy the string
    size_t index = 0;
    while (true//there is a break statement inside
    ) 
    {
        //find a substring to replace
        index = str.find(find, index);
        //if nothing found, stop.
        if (index == string::npos)
        {
            break;
        }

        //replace what was found
        str.replace(index, find.size(), replace);
        numReplaced++;

        //advance the index so that the replaced text is 
        //not searched
        index += replace.size();
    }
    return str;
}


//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:       lowerString
//	Input:      a string with letters
//	Output:     a string with lowercase letters
//	Purpose:    help with guessing uppercase letters
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string lowerString(const string& mixedString)
{
    string temp = "";
    temp.reserve(mixedString.size());
    for(int i = 0; i < mixedString.size(); ++i)
    {
        temp.push_back(tolower(mixedString.at(i)));
    }
}
