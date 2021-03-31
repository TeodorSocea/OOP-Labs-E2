template <class T>
class vector
{
    T *elements;
    int elements_number;
    int size;

public:
    vector()
    {
        this->size = 1;
        this->elements_number = 0;
        this->elements = new T[size];
    }
};