#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "vector.h"
using namespace std;

int main()
{
    //Ex1

    vector<string> MyStringVector;
    MyStringVector.push_back("Ana");
    MyStringVector.push_back("are");
    MyStringVector.push_back("mere");
    MyStringVector.push_back("si");
    MyStringVector.push_back("banane");
    MyStringVector.push_back("si");
    MyStringVector.push_back("portocale");

    sort(MyStringVector.begin(), MyStringVector.end(), [](string &s1, string &s2) {
        if (s1.length() < s2.length())
            return 1;
        if (s1.length() == s2.length())
            if (s1 < s2)
                return 1;
        return 0;
    });

    for (int i = 0; i < MyStringVector.size(); i++)
    {
        cout << MyStringVector[i] << " ";
    }
    cout << "\n";
    vector<int> MyIntVector;
    MyIntVector.push_back(1);
    MyIntVector.push_back(2);
    MyIntVector.push_back(3);
    MyIntVector.push_back(4);
    MyIntVector.push_back(5);
    MyIntVector.push_back(6);
    MyIntVector.push_back(7);

    //Ex2

    auto f = [](vector<int> vec) {
        auto max = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > max)
                max = vec[i];
        }
        return max;
    };

    cout << f(MyIntVector) << '\n';

    //Ex3

    MyVector array(20);

    array.Add(1);
    array.Add(1);
    array.Add(1);
    array.Add(1);
    array.Add(1);
    array.Add(1);
    array.Add(1);

    array.Iterate([](int &e1) {
        return e1 + 1;
    });

    for (int i = 0; i < array.getSize(); i++)
    {
        cout << array[i] << " ";
    }
    cout << '\n';

    array.Filter([](int &e1) {
        return e1 % 2 == 0;
    });

    for (int i = 0; i < array.getSize(); i++)
    {
        cout << array[i] << " ";
    }
    cout << '\n';
}