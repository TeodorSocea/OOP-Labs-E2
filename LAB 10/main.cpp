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
    cout << "\n";
    vector<int> MyIntVector;
    MyIntVector.push_back(1);
    MyIntVector.push_back(2);
    MyIntVector.push_back(3);
    MyIntVector.push_back(4);
    MyIntVector.push_back(5);
    MyIntVector.push_back(6);
    MyIntVector.push_back(7);

    auto f = [](vector<int> vec) {
        int max = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] > max)
                max = vec[i];
        }
        return max;
    };

    cout << f(MyIntVector) << '\n';
}