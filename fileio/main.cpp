#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstdlib>
#include <string>
using std::string;

int main()
{
    //get filename from user
    string out_filename;
    cout << "Enter output file path : ";
    cin >> out_filename;

    ofstream out_file;
    out_file.open(out_filename.c_str());
    if(!out_file.is_open())
    {
        cout << "failed to open output file.\n";
        exit(1);
    }

    //get filename from user
    string in_filename;
    cout << "Enter file path : ";
    cin >> in_filename;
    //in_filename = "mydata.txt";

    ifstream in_file;
    in_file.open(in_filename.c_str());
    if(!in_file.is_open())
    {
        cout << "failed to open input file.\n";
        exit(1);
    }

    int numWrites = 10;
    for(int i = 0; i < numWrites; ++i)
    {
        out_file << (i+1) * 111 % 1000 << endl;
    }

    string input;
    int numInputs = 10;
    for(int i = 0; i < numInputs; ++i)
    {
        in_file >> input;
        cout << "" << input << ", ";
    }
    cout << endl;
    return 0;
}