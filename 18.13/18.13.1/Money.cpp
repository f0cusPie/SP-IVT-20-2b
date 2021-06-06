#include "Money.h"
#include <iostream>

using namespace std;

Money& Money::operator=(const Money& t)
{
    if (&t == this)
        return *this;

    _dollars = t._dollars;
    _cents = t._cents;
    return *this;
}

Money& Money::operator++()
{
    int temp = _dollars * 60 + _cents;
    temp++;

    _dollars = temp / 60;
    _cents = temp % 60;
    return *this;
}

Money Money::operator ++(int)
{
    int temp = _dollars * 60 + _cents;
    temp++;
    Money t(_dollars, _cents);

    _dollars = temp / 60;
    _cents = temp % 60;
    return t;
}

Money Money::operator+(const Money& t)
{
    int temp1 = _dollars * 60 + _cents;
    int temp2 = t._dollars * 60 + t._cents;

    Money p;
    p._dollars = (temp1 + temp2) / 60;
    p._cents = (temp1 + temp2) % 60;
    return p;
}

Money Money::operator/(const int t)
{
    int temps = _cents;
    int tempm = _dollars;

    Money p;
    p._dollars = tempm / t;
    p._cents = temps / t;
    return p;
}

Money Money::operator / (const Money& t)
{
    int temps = _cents;
    int tempm = _dollars;

    Money p;
    if (t._dollars != 0)
        p._dollars = tempm / t._dollars;
    else
        p._dollars = tempm;

    if (t._cents != 0)
        p._cents = temps / t._cents;
    else
        p._cents = temps;

    return p;
}

bool Money::operator<(const Money& t)
{
    if (_dollars == t._dollars)
    {
        if (_cents < t._cents)
            return true;
        else
            return false;
    }
    else
    {
        if (_dollars < t._dollars)
            return true;
        else
            return false;
    }
}

//перегрузка операции больше
bool Money::operator>(const Money& t)
{
    if (_dollars == t._dollars)
    {
        if (_cents > t._cents)
            return true;
        else
            return false;
    }
    else
    {
        if (_dollars > t._dollars)
            return true;
        else
            return false;
    }
}


//перегрузка операции сравнения
bool Money::operator==(const Money& t)
{
    if (t._cents == _cents && t._dollars == _dollars)
        return true;
    else
        return false;
}

//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
    cout << "dollars: ";
    in >> t._dollars;

    cout << "cents: ";
    in >> t._cents;

    return in;
}

//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
    return (out << t._dollars << " : " << t._cents);
}