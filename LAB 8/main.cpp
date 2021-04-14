#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <regex>

using std::ifstream;
using std::regex;
using std::remove_if;
using std::sregex_token_iterator;
using std::string;
using std::vector;

ifstream in("in.txt");

vector<string> parsePhrase(const string &str, const regex &re)
{
    sregex_token_iterator it(str.begin(), str.end(), re, -1);
    vector<string> parsed(it, {});

    parsed.erase(remove_if(parsed.begin(), parsed.end(), [](string const &s) { return s.size() == 0; }), parsed.end());

    return parsed;
}

int main()
{
    string phrase;
    getline(in, phrase);

    regex re(R"([\s|,|.|?|!]+)");

    vector<string> words = parsePhrase(phrase, re);

    for (auto word : words)
    {
        std::cout << word << '\n';
    }
}