#include <initializer_list>

class Sort

{

    int *data, count;

public:

    Sort(int, int, int);
    Sort(std::initializer_list<int>);
    Sort(int, int *);
    Sort(int...);
    Sort(char*);

    void InsertSort(bool ascendent=false);

    void QuickSort(bool ascendent=false);

    void BubbleSort(bool ascendent=false);

    void Print();

    int  GetElementsCount();

    int  GetElementFromIndex(int);

};