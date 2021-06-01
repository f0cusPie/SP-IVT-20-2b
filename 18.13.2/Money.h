#pragma once
#include <iostream>

using namespace std;

class Money
{
private:
    int
        _dollars,
        _cents;

public:

    Money()
    {
        _dollars = 0;
        _cents = 0;
    };

    Money(int m, int s)
    {
        _dollars = m;
        _cents = s;
    }

    Money(const Money& t)
    {
        _dollars = t._dollars;
        _cents = t._cents;
    }

    ~Money() {};

    int GetMin() { return _dollars; }
    int GetSec() { return _cents; }

    void SetMin(int m) { _dollars = m; }
    void SetSet(int s) { _cents = s; }

    Money& operator=(const Money&);

    Money& operator++();
    Money operator++(int);

    Money operator+(const Money&);
    bool operator==(const Money&);

    Money operator/(const int t);
    Money operator/(const Money&);

    bool operator<(const Money&);
    bool operator>(const Money&);

    friend istream& operator>>(istream& in, Money& t);
    friend ostream& operator<<(ostream& out, const Money& t);
};