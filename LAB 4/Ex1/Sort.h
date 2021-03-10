#include <initializer_list>
#include <cstring>
class Sort

{

    int count, *data; 

public:

    friend Sort operator+(int number_to_add, const Sort &input){
        int *new_arr = new int[input.count + 1];
        new_arr[0] = number_to_add;
        for(int i = 1; i < input.count + 1; i++){
            new_arr[i] = input.data[i-1];
        }
        Sort output(input.count+1, new_arr);
        return output;
    }

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

    ~Sort(){
        delete[] data;
    }

    Sort(const Sort& old_elements){
        count = old_elements.count;
        data = new int[count];
        for(int i = 0; i < count; i++){
            data[i] = old_elements.data[i];
        }
    }

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int);
};

int getNumbersCountFromInputString(char *);
void swap(int*, int*);