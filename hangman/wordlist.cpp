//	===============================================================
//  Filename:		wordlist.cpp
//  Title:          hangman_extracredit
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-21
//  Description:	load word list from file
//	===============================================================

#include "hangman.h"
#include <string>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <cassert>

using namespace std;


//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		loadWordlist
//	Input: 		filename (default "wordlist.txt")
//	Output:		vector<string> containing each word
//	Purpose:	read file in order to load the list into mem
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void loadWordlist(vector<string>& loadTo, const char* const filename)
{
	loadTo = vector<string>(0);
	ifstream in_file;
	in_file.open(filename);
	assert(!in_file.fail()); //exit if file failed to open
	while(true) //break in middle
	{
		string input;
		in_file >> input;

		if( in_file.eof() )
		{
			break;
		}

		loadTo.push_back(input);
	}
	in_file.close();
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		wordlist
//	Input: 		filename (default "wordlist.txt")
//	Output:		vector<string> containing each word
//	Purpose:	allow external use of the list of words
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
const vector<string>& wordlist(const char* const filename /*= "wordlist.txt"*/)
{	
	static const char* currentlyLoaded = "";
	static vector<string> wordlist;
	if(strcmp(filename, currentlyLoaded) == 0)
	{ //if the file is already loaded, don't load it again, just return.
		return wordlist;
	}
	assert(strcmp(filename, "")); //filename can't be empty
	loadWordlist(wordlist, filename);
	currentlyLoaded = filename;

	for(int i = 0; i < wordlist.size(); ++i)
	{
		string& word = wordlist.at(i);
		// remove spaces
		//wait no don't remove spaces
		int temp;
		//word = replaceAll(word, " ", "", temp);
		//lowercase every letter in the word
		for(int j = 0; j < word.size(); ++j)
		{
			//actually nvm don't lowercase it
			//word.at(i) = tolower(word.at(i));
			assert(isalpha(word.at(i)));//found non-alpha letter in word
		}
	}

	return wordlist;
}

//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Name: 		randWord
//	Input: 		filename of word list
//	Output:		picks a random word
//	Purpose:	word for hangman
//	+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
string randWord(const char* const filename /*= "wordlist.txt"*/)
{

}