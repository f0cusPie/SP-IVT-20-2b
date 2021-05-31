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

    Pair operator-(Pair rightOperand);

    Pair operator+(const int rightOperand);

    Pair operator+(const double rightOperand);

    Pair operator+(Pair rightOperand);

    Pair operator/(int rightOperand);

    bool operator!=(Pair rightOperand);

    friend istream& operator>>(istream& stream, Pair& element);
    friend ostream& operator<<(ostream& stream, Pair element);
};
