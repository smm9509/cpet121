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
//	Name: 		
//	Input: 		
//	Output:		
//	Purpose:	
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string replaceAll(
    const string& text, 
    const string& find, 
    const string& replace
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

        //advance the index so that the replaced text is 
        //not searched
        index += replace.size();
    }
    return str;
}
