#include "mnogochlen.h"
#include <math.h>

double plusF(double a, double b) {
    return a + b;
}

double minusF(double a, double b) {
    return a - b;
}

Mnogochlen::Mnogochlen(int adegree) {
    degree = adegree;
    coef = new double[degree];

    for (int i = 0; i < degree; i++)
        coef[i] = 0.0;
}

Mnogochlen::Mnogochlen(int adegree, double* acoef) {
    degree = adegree;
    coef = new double[degree];

    for (int i = 0; i < degree; i++)
        coef[i] = acoef[i];
}

Mnogochlen::Mnogochlen(const Mnogochlen& p) {
    degree = p.degree;
    coef = new double[degree];

    for (int i = 0; i < degree; i++)
        coef[i] = p.coef[i];
}

Mnogochlen::~Mnogochlen() {
    delete[] coef;
}

QString Mnogochlen::ToString() const {
    QString str = "";

    bool p = true;
    QString c, op;

    for (int i = degree - 1; i >= 0; i--) {
        if (abs(coef[i] - 0) > pow(10, -6)) {
            c = (abs(coef[i]) == 1)? "" : QString::number(abs(coef[i]));
            op = (coef[i] > 0)? (p)? "" : "+" : "-";

            if (i == 1)
                str += op + c + "x ";
            else if (i == 0)
                str += op + QString::number(abs(coef[i]));
            else
                str += op + c + "x^" + QString::number(i) + " ";

            p = false;
        }
    }

    return str;
}

void Mnogochlen::reduce(void) {
    int tdeg = degree;
    for (int i = degree - 1; i >= 0; i--) {
        if (coef[i] != 0.0)
            break;
        else
            tdeg--;
    }

    degree = tdeg;
}

Mnogochlen baza(const Mnogochlen& p1, const Mnogochlen& p2, double op(double, double)) {
    Mnogochlen *pmax, *pmin;

    if (p1.degree > p2.degree) {
        pmax = (Mnogochlen*)&p1;
        pmin = (Mnogochlen*)&p2;
    }
    else {
        pmax = (Mnogochlen*)&p2;
        pmin = (Mnogochlen*)&p1;
    }

    int min_degree = pmin->degree;
    int max_degree = pmax->degree;

    Mnogochlen res(max_degree);

    for (int i = 0; i < max_degree; i++) {
        if (i < min_degree)
            res.coef[i] = op(pmax->coef[i], pmin->coef[i]);
        else
            res.coef[i] = pmax->coef[i];
    }

    return res;
}

Mnogochlen& Mnogochlen::operator=(const Mnogochlen& p) {
    if (this == &p)
        return *this;

    degree = p.degree;

    coef = new double[degree];
    for (int i = 0; i < degree; i++)
        coef[i] = p.coef[i];

    return *this;
}

Mnogochlen operator + (const Mnogochlen& p1, const Mnogochlen& p2) {
    return baza(p1, p2, plusF);
}

Mnogochlen operator - (const Mnogochlen& p1, const Mnogochlen& p2) {
    return baza(p1, p2, minusF);
}

Mnogochlen operator * (const Mnogochlen& p1, const Mnogochlen& p2) {
    Mnogochlen res(p1.degree + p2.degree - 1);

    for (int i = 0; i < p1.degree; i++)
        for (int j = 0; j < p2.degree; j++)
            res.coef[i + j] += p1.coef[i] * p2.coef[j];

    return res;
}

Mnogochlen operator / (const Mnogochlen& p1, const Mnogochlen& p2) {
    Mnogochlen temp = p1;
    int rdeg = temp.degree - p2.degree + 1;
    Mnogochlen res(rdeg);

    for (int i = 0; i < rdeg; i++) {
        res.coef[rdeg - i - 1] = temp.coef[temp.degree - i - 1] / p2.coef[p2.degree - 1];
        for (int j = 0; j < p2.degree; j++)
            temp.coef[temp.degree - j - i - 1] -= p2.coef[p2.degree - j - 1] * res.coef[rdeg - i - 1];
    }

    temp.reduce();
    return res;
}

Mnogochlen Mnogochlen::Stepen(int grade) {
    Mnogochlen temp(*this);
    Mnogochlen result(1, new double[1] { 1 });

    for (int i = 0; i < grade; i++)
        result = result * temp;

    return result;
}

Mnogochlen Mnogochlen::Stepen(const Mnogochlen& grade) {
    return Stepen(grade.coef[0]);
}

double Mnogochlen::F(double x)
{
    double value = 0;
    for (int i = degree - 1; i >= 0; i--)
        value += pow(x, i) * coef[i];

    return value;
}
