#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::string;

ifstream in("in.txt");

int main()
{
    string phrase;
    getline(in, phrase);
    std::cout << phrase;
}