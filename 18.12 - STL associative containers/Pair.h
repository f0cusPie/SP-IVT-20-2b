#pragma once
#include <istream>
using namespace std;

class Pair
{
private:
    int _first;
    double _second;

public:
    Pair();

    Pair(int first, double second);

    int GetFirstElement();

    double GetSecondElement();

    void SetFirst(int first);

    void SetSecond(double second);

    ~Pair();

    Pair operator-(Pair secondOperand);

    Pair operator+(const int secondOperator);

    Pair operator+(const double secondOperator);

    Pair operator+(Pair rightOperand);

    Pair operator/(int rightOperand);

    //Pair operator=(int rightOperand);

    Pair& operator=(Pair rightOperand);

    bool operator!=(Pair secondOperand);

    bool operator<(const Pair& rightOperand);;

    friend istream& operator>>(istream& stream, Pair& element);
    friend ostream& operator<<(ostream& stream, Pair element);
};
