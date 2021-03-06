//	===============================================================
//  Filename:		hangman.h
//	Title:			hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-18
//  Description:    2022S_dp4_Hangman
//                  declare functions
//	===============================================================

#pragma once
#include <string>
#include <vector>

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		replaceALL
//	Input: 		text body, text to find, replace found text with
//	Output:		a string similar to body with text replaced the
//              normal way
//	Purpose:	find and replace
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
std::string replaceAll(
    const std::string& text, 
    const std::string& find, 
    const std::string& replace,
    int& numReplaced
);

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		print
//	Input: 		a string
//	Output:		print to console
//	Purpose:	display things to the user
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void print(const std::string& text);

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
void dispayWord(const std::string& word);

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		printGallows
//	Input: 		an integer 0 thru 8 indicating the number of
//				mistakes the player has made
//	Output:		prints gallows with relevant parts showing
//	Purpose:	display part of game state to user
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printGallows(const int status);

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		userInput
//	Input: 		user types a line of text
//	Output:		returns the first character from that line
//	Purpose:	get user guess
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
char userInput();

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		wordlist
//	Input: 		filename (default "wordlist.txt")
//	Output:		vector<string> containing each word
//	Purpose:	allow external use of the list of words
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const std::vector<std::string>& wordlist(const char* const filename = "wordlist.txt");

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		randWord
//	Input: 		filename of word list
//	Output:		picks a random word
//	Purpose:	word for hangman
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
std::string randWord(const char* const filename = "wordlist.txt");


//modified version of replaceAll function
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		targetedReplace
//	Input: 		places - will search in this string
//				workArea - when found find in places, use 
//					the index to replace in this string
//				find - string to find
//				replace - string to overwrite in workArea at 
//					index
//	Output:		overwrites some parts of workArea
//	Purpose:	allow printGallows to work based on the const
//				templates present.
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void targetedReplace(
    const std::string& places, 
	std::string& workArea,
    const std::string& find, 
    const std::string& replace
);

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		convertToStars
//	Input: 		a string with letters and spaces
//	Output:		a string with asterisks and spaces
//	Purpose:	obfuscate answer from player
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
std::string convertToStars(const std::string& word);

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:		log
//	Input:		a string
//	Output:		writes the string as a line to the output
//	Purpose:	satisfy logging requirement
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void log(const std::string& output);

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:		closeLog
//	Input:		none
//	Output:		none
//	Purpose:	close the ofstream object
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void closeLog();

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:       lowerString
//	Input:      a string with letters
//	Output:     a string with lowercase letters
//	Purpose:    help with guessing uppercase letters
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
std::string lowerString(const std::string& mixedString);