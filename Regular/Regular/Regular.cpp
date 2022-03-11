#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    unsigned int counter = 0;
    string str, input;
    cout << "Enter the name of the input file: \n";
    getline(cin, input);
    ifstream fin;
    fin.open(input);

    if (!fin.is_open())
    {
        cout << "Check the name of the input file \n";
        return 1;
    }

    regex regular("^( )*(((0[1-9]|[12][0-9]|3[01])/((0[13578]|1[02]))|((0[1-9]|[12][0-9]|30)/(0[469]|11))|(0[1-9]|[1][0-9]|2[0-8])/(02))/((1[89]|20)[0-9][0-9]))|(29/02/((1[89]|20)(0[48]|[2468][048]|[13579][26])|(2000)))((\s+)|($))");

    while (!fin.eof())
    {
        getline(fin, str);
        if (regex_search(str.c_str(), regular))
        {
            counter++;
        }

    }
    cout << counter << "\n";
    return  0;
}