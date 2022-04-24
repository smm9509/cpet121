//	===============================================================
//   Filename:		log.cpp
//   Title:          hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-21
//   Description:	write game state to file
//	===============================================================

#include "hangman.h"
#include <fstream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:		logFile
//	Input:		filename
//	Output:		ofstream object
//	Purpose:	contain static ofstream object to avoid 
//				re-opening file
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ofstream& logFile(const char* const filename = "results_1.txt")
{
	static const char* currentlyLoaded = "";
	static ofstream outputStream;
	if(strcmp(filename, currentlyLoaded) == 0)
	{ //if the file is already loaded, don't load it again, just return.
		assert(outputStream.is_open()); //make sure file is still valid
		return outputStream;
	}
	assert(strcmp(filename, "")); //filename can't be empty
	outputStream = ofstream();
	outputStream.open(filename);
	assert(!outputStream.fail()); //exit if file failed to open
	currentlyLoaded = filename;
	return outputStream;
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:		log
//	Input:		a string
//	Output:		writes the string as a line to the output
//	Purpose:	satisfy logging requirement
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void log(string& output)
{
	logFile() << output << endl;
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name:		closeLog
//	Input:		none
//	Output:		none
//	Purpose:	close the ofstream object
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void closeLog()
{
	logFile().close();
}