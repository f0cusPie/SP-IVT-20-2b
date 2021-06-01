#pragma once
#include <QString>

#ifndef MNOGOCHLEN_H
#define MNOGOCHLEN_H

class Mnogochlen
{
private:
    int degree;
    double* coef;

    Mnogochlen (int adegree);
    void reduce(void);

    friend Mnogochlen baza(const Mnogochlen& m1, const Mnogochlen& m2, double op(double, double));

public:
    Mnogochlen(int, double*);
    Mnogochlen(const Mnogochlen& copied);
    ~Mnogochlen();

    QString ToString() const;

    friend Mnogochlen operator+(const Mnogochlen& m1, const Mnogochlen& m2);
    friend Mnogochlen operator-(const Mnogochlen& m1, const Mnogochlen& m2);
    friend Mnogochlen operator*(const Mnogochlen& m1, const Mnogochlen& m2);
    friend Mnogochlen operator/(const Mnogochlen& m1, const Mnogochlen& m2);

    Mnogochlen& operator = (const Mnogochlen& p);
    Mnogochlen Stepen(int grade);
    Mnogochlen Stepen(const Mnogochlen& grade);

    double F(double x);
};

#endif // MNOGOCHLEN_H
