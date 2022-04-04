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
#include <vector>
using std::vector;

int main()
{
    vector<double> myData;
    const char * const IN_FILENAME = "input.txt";
    const char * const OUT_FILENAME = "output.txt";
    {
        ifstream in_file;
        in_file.open(IN_FILENAME);

        if(!in_file.is_open())
        {
            cout << "failed to open input file.\n";
            exit(1);
        }



        cout << "input data :" << endl;
        while(true) //break in middle
        {
            double input;
            in_file >> input;

            if( in_file.eof() )
            {
                break;
            }

            myData.push_back(input);
            cout << input << ", ";

        }
        in_file.close();
        cout << endl;
    }

    {
        ofstream out_file;
        out_file.open(OUT_FILENAME);
        
        if(!out_file.is_open())
        {
            cout << "failed to open output file.\n";
            exit(1);
        }

        for(int i = 0; i < myData.size(); ++i)
        {
            out_file << myData.at(i) / 10.0 << endl;
        }

        out_file.close();
    }

    {
        ifstream in_file;
        in_file.open(OUT_FILENAME);

        if(!in_file.is_open())
        {
            cout << "failed to open outputted file.\n";
            exit(1);
        }



        cout << "result :" << endl;
        while(true) //break in middle
        {
            double input;
            in_file >> input;

            if( in_file.eof() )
            {
                break;
            }

            cout << input << ", ";

        }
        in_file.close();
        cout << endl;
    }


    return 0;
}