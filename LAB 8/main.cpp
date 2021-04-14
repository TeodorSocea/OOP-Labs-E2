#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <regex>
#include <map>
#include <utility>
#include <queue>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

using std::cout;
using std::ifstream;
using std::map;
using std::pair;
using std::priority_queue;
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

class cmp
{
public:
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) const
    {
        if (a.second < b.second)
            return true;
        else if (a.second == b.second)
            return a.first > b.first;
        else
            return false;
    };
};

void print(priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> &pqueue)
{
    while (!pqueue.empty())
    {
        pair<string, int> word = pqueue.top();
        cout << word.first << " => " << word.second << '\n';
        pqueue.pop();
    }
}

int main()
{
    {
        string phrase;
        getline(in, phrase);

        regex re(R"([\s|,|.|?|!]+)");

        vector<string> words = parsePhrase(phrase, re);

        for (auto word : words)
        {
            std::cout << word << '\n';
        }
        cout << '\n';

        map<string, int> words_map = generateCaseInsesitiveMap(words);

        for (auto it = words_map.begin(); it != words_map.end(); it++)
        {
            std::cout << it->first << " " << it->second << '\n';
        }
        cout << '\n';

        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> sorted_words(words_map.begin(), words_map.end());

        print(sorted_words);
    }
    _CrtDumpMemoryLeaks();
    return 0;
}