#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <regex>
#include <map>

using std::ifstream;
using std::map;
using std::regex;
using std::remove_if;
using std::sregex_token_iterator;
using std::string;
using std::transform;
using std::vector;

ifstream in("in.txt");

vector<string> parsePhrase(const string &str, const regex &re)
{
    sregex_token_iterator it(str.begin(), str.end(), re, -1);
    vector<string> parsed(it, {});

    parsed.erase(remove_if(parsed.begin(), parsed.end(), [](string const &s) { return s.size() == 0; }), parsed.end());

    return parsed;
}

map<string, int> generateCaseInsesitiveMap(const vector<string> &words)
{
    map<string, int> output;
    for (auto word : words)
    {
        transform(word.begin(), word.end(), word.begin(), [](char c) { return tolower(c); });
        output[word]++;
    }
    return output;
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

    map<string, int> words_maps = generateCaseInsesitiveMap(words);

    for (auto it = words_maps.begin(); it != words_maps.end(); it++)
    {
        std::cout << it->first << " " << it->second << '\n';
    }
}