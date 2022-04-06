//	===============================================================
//  Filename:		main.cpp
//	Title:			Homework #2 -Nursery Rhymes I/O Character Files
//	Course:			CPET.121.01/05-06 - Computational Prob Solving I
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-06
//  Description:    make vowels uppercase
//	===============================================================


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
    ifstream inF;
    inF.open("mary.txt");
    if(inF.fail())
    {
        exit(1);
    }

    ofstream outF;
    outF.open("mary2.txt");
    if(outF.fail())
    {
        exit(2);
    }

    char data;

    inF.get(data); //can also use std::getline from <string>
    while(!inF.eof())
    {
        outF.put(
            tolower(data) == 'a' ||
            tolower(data) == 'e' ||
            tolower(data) == 'i' ||
            tolower(data) == 'o' ||
            tolower(data) == 'u' ||
            tolower(data) == 'y'
            ?
            toupper(data)

            :
            data
            );
        inF.get(data);
    }

    inF.close();
    outF.close();

    return 0;
} 