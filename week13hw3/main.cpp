//  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//	Title:			Homework #3 - String File Input / Output
//  Filename:		main.cpp
//  Course:         Computational Problem Solving CPET-121
//	Developer:		smm9509@rit.edu
//  Date:           2022-04-11
//  Description:    calculate stuff from files
//  
//  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::getline;
using std::vector;

struct Employee
{
    char letter;
    string name;
    string idNum;
    double hourlyRate;
    double hoursWorked;
    double payThisWeek;
};


int main()
{
    //this is my code

    ifstream inF;
    inF.open("pay_in.txt");
    if(inF.fail())
    {
        exit(1);
    }

    ofstream outF;
    outF.open("output.txt");
    if(outF.fail())
    {
        exit(2);
    }

    vector<Employee> vect(0);

    bool keepGoing = true;
    do
    {
        char letter;
        string name;
        string idNum;
        double payRate;
        double hours;
        
        inF >> letter;
        inF >> name;
        inF >> idNum;
        inF >> payRate;
        inF >> hours;

        if(inF.eof())
        {
            keepGoing = false;
            break;
        }
        Employee temp = Employee();
        temp.letter     = letter;
        temp.name       = name;
        temp.idNum      = idNum;
        temp.hourlyRate = payRate;
        temp.hoursWorked= hours;
        vect.push_back(temp);
    } while (keepGoing);
    
    for(int i = 0; i < vect.size(); i++)
    {
        vect.at(i).payThisWeek = 
            vect.at(i).hourlyRate * vect.at(i).hoursWorked;
        outF << std::setw(10) << std::left
        << vect.at(i).name;
        outF << std::setw(0)
        << "$ " << std::fixed << std::setprecision(2)
        << vect.at(i).payThisWeek << ' ' << endl;
    }

    inF.close();
    outF.close();

    return 0;
}