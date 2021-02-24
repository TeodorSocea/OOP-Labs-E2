struct Catalog{
    float math, eng, his;
};
class Student{
    char* name;
    Catalog grades;
    float avg;
    public:
        void setName(char*);
        void setMath(float);
        void setEng(float);
        void setHis(float);

        char* getName();
        float getMath();
        float getEng();
        float getHis();
        float getAvg();
};
