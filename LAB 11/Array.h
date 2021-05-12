
#include <exception>
#include <string>
#include <stdlib.h>
class ArrayException : public std::exception
{
    virtual const char *what() const throw() = 0;
};
template <class T>
class IndexOutOfBounds : public ArrayException
{
    Array<T> *adress;
    int index;

public:
    IndexOutOfBounds(Array<T> *_adress, int _index) : adress{_adress}, index{_index} {}

    const char *what() const throw()
    {
        std::string Message = "Index out of bounds at " + itoa(adress) + " and index " + itoa(index);
        return Message;
    }
};

template <class T>
class CapacityExceeded : public ArrayException
{
    Array<T> *adress;
    int size;

public:
    CapacityExceeded(Array<T> *_adress, int _size) : adress{_adress}, size{_size} {}

    const char *what() const throw()

    {
        std::string Message = "Capacity exceeded at " + itoa(adress) + " with capacity " + itoa(size);
        return Message;
    }
};

class Compare

{

public:
    virtual int CompareElements(void *e1, void *e2) = 0;
};

template <class T>

class ArrayIterator

{

private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator

public:
    ArrayIterator();

    ArrayIterator &operator++();

    ArrayIterator &operator--();

    bool operator=(ArrayIterator<T> &);

    bool operator!=(ArrayIterator<T> &);

    T *GetElement();
};

template <class T>

class Array

{

private:
    T **List; // lista cu pointeri la obiecte de tipul T*

    int Capacity; // dimensiunea listei de pointeri

    int Size; // cate elemente sunt in lista

public:
    Array() // Lista nu e alocata, Capacity si Size = 0
    {
        Capacity = 0;
        Size = 0;
        List = nullptr;
    }
    ~Array() // destructor
    {
        for (int i = 0; i < Capacity; i++)
        {
            delete List[i];
        }
        delete[] List;
    }
    Array(int capacity) // Lista e alocata cu 'capacity' elemente
    {
        Size = 0;
        Capacity = capacity;
        List = new T *[Capacity];
        for (int i = 0; i < Capacity; i++)
        {
            List[i] = new T;
        }
    }
    Array(const Array<T> &otherArray) // constructor de copiere
    {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T *[Capacity];

        for (int i = 0; i < Capacity; i++)
        {
            List[i] = new T;
        }

        for (int i = 0; i < Size; i++)
        {
            *(List[i]) = *(otherArray.List[i]);
        }
    }

    T &operator[](int index); // arunca exceptie daca index este out of range

    const Array<T> &operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this

    const Array<T> &Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T> &Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

    const Array<T> &Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T

    void Sort(int (*compare)(const T &, const T &)); // sorteaza folosind o functie de comparatie

    void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

    int BinarySearch(const T &elem); // cauta un element folosind binary search in Array

    int BinarySearch(const T &elem, int (*compare)(const T &, const T &)); //  cauta un element folosind binary search si o functie de comparatie

    int BinarySearch(const T &elem, Compare *comparator); //  cauta un element folosind binary search si un comparator

    int Find(const T &elem); // cauta un element in Array

    int Find(const T &elem, int (*compare)(const T &, const T &)); //  cauta un element folosind o functie de comparatie

    int Find(const T &elem, Compare *comparator); //  cauta un element folosind un comparator

    int GetSize();

    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();

    ArrayIterator<T> GetEndIterator();
};