class Number

{

    char *value;
    int base;

public:
    Number(const char *value, int base); // where base is between 2 and 16

    ~Number();

    Number(const Number &n);

    Number(Number &&n);

    void setValue(const char *);

    char *getValue();

    void operator=(Number &n);

    friend void operator+(Number &a, Number b);

    friend void operator-(Number &n);

    void operator!();

    char operator[](int);

    int operator>(Number &n);

    int operator<(Number &n);

    int operator>=(Number &n);

    int operator<=(Number &n);

    int operator==(Number &n);

    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount(); // returns the number of digits for the current number

    int GetBase(); // returns the current base
};