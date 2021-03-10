#include <initializer_list>
#include <cstring>
class Sort

{

    int *data, count;

public:
    Sort operator+(int number_to_add)
    {
        Sort output_elements(this->count, this->data);
        output_elements.count++;
        int *new_arr = new int[this->count+1];
        memcpy(new_arr, output_elements.data, this->count * sizeof(int));
        new_arr[this->count] = number_to_add;
        delete[] output_elements.data;
        output_elements.data = new_arr;
        return output_elements;
    }

    Sort(int, int, int);
    Sort(std::initializer_list<int>);
    Sort(int, int *);
    Sort(int...);
    Sort(char *);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int);
};

int getNumbersCountFromInputString(char *);