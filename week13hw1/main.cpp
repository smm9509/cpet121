#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::getline;

int main()
{
    const int SIZE = 25;
    vector<double> vect(0);
    vect.reserve(SIZE);

    for(int i = 0; i < SIZE; ++i)
    {
        double temp;
        cin >> temp;
        vect.push_back(temp);
    }

    double sum = 0;
    for(int i = 0; i < vect.size(); ++i)
    {
        sum += vect.at(i);
    }
    double average = sum / vect.size();

    ofstream outF;
    string outFname;
    cin.ignore();
    cout << "Enter filename (expecting \"s_a.dat\"): ";
    getline(cin, outFname);
    outF.open(outFname.c_str());
    if(outF.fail())
    {
        printf("could not open the file"
        " at \"%s\", sorry.\n", outFname);
        exit(1);
    }

    outF << sum << ' ' << average << ' ' << endl;

    return 0;
}