//  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Title:			Homework #2 -Nursery Rhymes I/O Character Files
//  Filename:		main.cpp
//  Course:         Computational Problem Solving CPET-121
//	Developer:		smm9509@rit.edu
//	Date:			2022-04-11
//  Description:    make vowels uppercase
//  
//  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


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
    //this is my code
    
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