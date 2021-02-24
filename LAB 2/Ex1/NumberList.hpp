class NumberList{
    int numbers[10];
    int count;
    public:
        void Init();
        bool Add(int x);
        void Sort();
        void Print();
};
void swap(int*, int*);