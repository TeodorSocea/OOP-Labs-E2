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
    T pop()
    {
        if (this->elements_number == 0)
            throw "Empty vector";
        T output = this->elements[--this->elements_number];
        if (this->elements_number * 2 == this->size)
        {
            int newSize = this->size / 2;
            T *auxElements = new T[newSize];
            std::memcpy(auxElements, this->elements, this->elements_number * sizeof(T));
            delete[] this->elements;
            this->size = newSize;
            this->elements = auxElements;
        }
        return output;
    }
    void remove(int index)
    {
        if (this->elements_number <= index)
            throw "No element at index";
        std::memcpy(this->elements + index, this->elements + index + 1, (--this->elements_number - index) * sizeof(T));
        if (this->elements_number * 2 == this->size)
        {
            int newSize = this->size / 2;
            T *auxElements = new T[newSize];
            std::memcpy(auxElements, this->elements, this->elements_number * sizeof(T));
            delete[] this->elements;
            this->size = newSize;
            this->elements = auxElements;
        }
    }
    void insert(T elem, int index)
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
        std::memcpy(this->elements + index + 1, this->elements + index, (this->elements_number++ - index) * sizeof(T));
        this->elements[index] = elem;
    }
    const T &get(int index)
    {
        if (this->elements_number <= index)
            throw "No element at index";
        const T &output = this->elements[index];
        return output;
    }
    const T &operator[](int index)
    {
        if (this->elements_number <= index)
            throw "No element at index";
        return &this->elements[index];
    }
    void set(T obj, int index)
    {
        this->elements[index] = obj;
    }
    int count()
    {
        return this->elements_number;
    }
    void sort()
    {
        for (int i = 0; i < this->elements_number; i++)
            for (int j = i + 1; j < this->elements_number; j++)
                if (this->elements[i] > this->elements[j])
                {
                    std::swap(this->elements[i], this->elements[j]);
                }
    }
    void sort(int(cmp)(T, T))
    {
        for (int i = 0; i < this->elements_number; i++)
            for (int j = i + 1; j < this->elements_number; j++)
                if (cmp(this->elements[i], this->elements[j]))
                {
                    std::swap(this->elements[i], this->elements[j]);
                }
    }
};