#include <exception>
class IndexOutOfBounds : public std::exception
{
public:
    IndexOutOfBounds() = default;

    virtual const char *what() const throw()

    {

        return "Index out of bounds!";
    }
};
class CapacityExceeded : public std::exception
{
public:
    CapacityExceeded() = default;

    virtual const char *what() const throw()

    {

        return "Capacity exceeded!";
    }
};

class MyVector
{
private:
    int Size, Capacity;
    int *Elements;

public:
    bool Add(int);          // return true if the value was added. As a result, the size of the vector increases with one.
    bool Delete(int index); // returns true if the value from the index was removed. As a result, the size of the vector decreases with one.
    MyVector(int);
    ~MyVector();
    int &operator[](int);
    int getSize();
};