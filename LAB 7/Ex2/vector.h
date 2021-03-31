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
    ~vector()
    {
        delete[] this->elements;
    }
    vector(const vector &v)
    {
        this->size = v.size;
        this->elements_number = v.elements_number;
        this->elements = new T[this->size];
        std::memcpy(this->elemenst, v.elements, v.elements_number * sizeof(T));
    }
    vector(vector &&v)
    {
        this->size = v.size;
        this->elements_number = v.elements_number;
        this->elements = new T[this->size];
        std::memcpy(this->elemenst, v.elements, v.elements_number * sizeof(T));
        v.size = 0;
        v.elements_number = 0;
        delete[] v.elements;
    }
    void push(T elem)
    {
        if (this->elements_number == this->size)
        {
            int newSize = this->size * 2;
            T *auxElements = new T[newSize];
            std::memcpy(auxElements, this->elements, this->elements_number * sizeof(T));
            delete[] this->elements;
            this->size = newSize;
            this->elements = auxElements;
        }
        this->elements[this->elements_number++] = elem;
    }
};