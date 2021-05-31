#include <iostream>
#include "Pair.h"
using namespace std;

Pair::Pair()
{
    _first = rand() % 100;
    _second = rand() % 10000 / 100.0;
}

Pair::Pair(int first, double second)
{
    _first = first;
    _second = second;
}

int Pair::GetFirstElement()
{
    return _first;
}

double Pair::GetSecondElement()
{
    return _second;
}

void Pair::SetFirst(int first)
{
    _first = first;
}

void Pair::SetSecond(double second)
{
    _second = second;
}

Pair::~Pair()
{

}

Pair Pair::operator-(Pair secondOperand)
{
    Pair res;
    res._first = this->_first - secondOperand._first;
    res._second = this->_second - secondOperand._second;
    return res;
}

Pair Pair::operator+(const int secondOperator)
{
    Pair res;
    res._first = this->_first + secondOperator;
    res._second = this->_second;
    return res;
}

Pair Pair::operator+(const double secondOperator)
{
    Pair res;
    res._first = this->_first;
    res._second = this->_second + secondOperator;
    return res;
}

Pair Pair::operator+(Pair rightOperand)
{
    Pair res;
    res._first = this->_first + rightOperand._first;
    res._second = this->_second + rightOperand._second;
    return res;
}

Pair Pair::operator/(int rightOperand)
{
    Pair res;
    res._first = this->_first / rightOperand;
    res._second = this->_second / rightOperand;
    return res;
}

bool Pair::operator!=(Pair secondOperand)
{
    return _first != secondOperand._first && _second != secondOperand._second;
}

/*
Pair Pair::operator=(int rightOperand)
{
    Pair res;
    res._first = rightOperand;
    res._second = rightOperand;
    return res;
}
*/

Pair& Pair::operator=(Pair rightOperand)
{
    Pair res;
    res._first = rightOperand._first;
    res._second = rightOperand._second;
    return res;
}

bool Pair::operator<(const Pair& rightOperand)
{
    return this->_first + this->_second < rightOperand._first + rightOperand._second;
}

istream& operator>>(istream& stream, Pair& element)
{
    stream >> element._first;
    stream >> element._second;
    return stream;
}

ostream& operator<<(ostream& stream, Pair element)
{
    stream << element._first << ":" << element._second;
    return stream;
}