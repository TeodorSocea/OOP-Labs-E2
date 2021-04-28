#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> MyVector;

    MyVector.push_back("Ana");
    MyVector.push_back("are");
    MyVector.push_back("mere");
    MyVector.push_back("si");
    MyVector.push_back("banane");
    MyVector.push_back("si");
    MyVector.push_back("portocale");

    sort(MyVector.begin(), MyVector.end(), [](string &s1, string &s2) {
        if (s1.length() < s2.length())
            return 1;
        if (s1.length() == s2.length())
            if (s1 < s2)
                return 1;
        return 0;
    });

    for (int i = 0; i < MyVector.size(); i++)
    {
        cout << MyVector[i] << " ";
    }
}