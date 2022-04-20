//	===============================================================
//  Filename:		gallows.cpp
//	Title:			hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-18
//  Description:    provide a function for printing the gallows in
//                  the console, with the hangman partially 
//                  displayed
//	===============================================================

#include "hangman.h"
#include <string>
#include <cassert>

using namespace std;

const char* COMPLETE_HANGMAN = 
"+---+"		"\n"
"|   |"		"\n"
"|   O"		"\n"
"|  \\|/"	"\n"
"|   |"		"\n"
"|  / \\"	"\n"
"|"			"\n"
"+------"	"\n";

const char* ZONES_FOR_FAILS = 
"+1111"		"\n"
"|   2"		"\n"
"|   3"		"\n"
"|  546"	"\n"
"|   4"		"\n"
"|  7 8"	"\n"
"|"			"\n"
"+------"	"\n";

void printGallows(const int status)
{
	string gallows = string(COMPLETE_HANGMAN);

	switch (status)
	{
	case 0:
		targetedReplace(ZONES_FOR_FAILS, gallows, "1", " ");
	case 1:
		targetedReplace(ZONES_FOR_FAILS, gallows, "2", " ");
	case 2:
		targetedReplace(ZONES_FOR_FAILS, gallows, "3", " ");
	case 3:
		targetedReplace(ZONES_FOR_FAILS, gallows, "4", " ");
	case 4:
		targetedReplace(ZONES_FOR_FAILS, gallows, "5", " ");
	case 5:
		targetedReplace(ZONES_FOR_FAILS, gallows, "6", " ");
	case 6:
		targetedReplace(ZONES_FOR_FAILS, gallows, "7", " ");
	case 7:
		targetedReplace(ZONES_FOR_FAILS, gallows, "8", " ");
	case 8:
		break;	
	default:
		assert("valid inputs are 0 thru 8"=="");
		break;
	}
}

//modified version of replaceAll function
void targetedReplace(
    const string& places, 
	string& workArea,
    const string& find, 
    const string& replace
)
{
	assert(find.size()==replace.size() && places.size() == workArea.size());
    size_t index = 0;
    while (true//there is a break statement inside
    ) 
    {
        //find a substring to replace
        index = places.find(find, index);
        //if nothing found, stop.
        if (index == string::npos)
        {
            break;
        }

        //replace what was found
        workArea.replace(index, find.size(), replace);

        //advance the index to not replace the same thing over and over again
        index += find.size();
    }
}
