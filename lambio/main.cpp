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

    char data;
    int vowelCount = 0;

    inF.get(data); //can also use std::getline from <string>
    while(!inF.eof())
    {
        switch(tolower(data))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
            vowelCount++;
            break;
        default:
            break;
        }

        inF.get(data);
    }

    inF.close();

    printf("there are %d vowels in lamb1.txt", vowelCount);

    return 0;
}