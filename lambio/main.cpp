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
    inF.open("lamb1.txt");
    if(inF.fail())
    {
        exit(1);
    }

    ofstream outF;
    outF.open("lamb2.txt");
    if(outF.fail())
    {
        exit(2);
    }

    char data;

    inF.get(data); //can also use std::getline from <string>
    while(!inF.eof())
    {
        outF.put(data);
        inF.get(data);
    }

    inF.close();
    outF.close();

    return 0;
}