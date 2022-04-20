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

