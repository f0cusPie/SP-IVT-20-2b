#include "Money.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

Money s;

int ReadNaturalNum()
{
    int x;
    do cin >> x; while (x <= 0);
    return x;
}

bool MoneyGreater(Money t)
{
    return t > s;
}

bool MoneyLess(Money t1, Money t2)
{
    return t1 > t2;
}

bool IsEqualToS(Money t)
{
    return t == s;
}

void PrintVector(vector<Money> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    cout << endl;
}

void PrintStack(stack<Money> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        cout << v.top() << endl;
        v.pop();
    }
    cout << endl;
}

stack<Money> NewInputStack(int n)
{
    Money a;
    stack<Money> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push(a);
    }
    return v;
}

Money AverageMoney(vector<Money> v)
{
    Money s = v[0];
    for (int i = 1; i < v.size(); i++)
        s = s + v[i];

    return s / v.size();
}

void DeleteMoney(Money& t)
{
    t = t / s;
}

vector<Money> stackToVector(stack<Money> st)
{
    vector<Money> v;
    int i = 0;
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
        i++;
    }
    return v;
}

stack<Money> vectorToStack(vector<Money> v)
{
    stack<Money> st;
    while (!v.empty())
    {
        st.push(v[0]);
        v.erase(v.begin());
    }
    return st;
}

int main()
{
    cout << "Input the count of items: ";
    int n = ReadNaturalNum();

    stack<Money> st;
    st = NewInputStack(n);
    PrintStack(st);

    vector<Money>::iterator i;
    vector<Money> v = stackToVector(st);
    i = max_element(v.begin(), v.end());

    cout << "Max value = " << *(i) << endl;
    Money m = *(i);

    s = AverageMoney(v);
    cout << "Average value = " << s << endl;

    replace_if(v.begin(), v.end(), MoneyGreater, m);
    cout << "Replacing..." << endl;

    st = vectorToStack(v);
    PrintStack(st);

    cout << "Reduce sort:\n";
    v = stackToVector(st);
    sort(v.begin(), v.end(), MoneyLess);

    st = vectorToStack(v);
    PrintStack(st);

    cout << "Increase sort:\n";
    v = stackToVector(st);
    sort(v.begin(), v.end());

    st = vectorToStack(v);
    PrintStack(st);

    cout << "Search by key: " << endl; cin >> s;
    v = stackToVector(st);

    i = find_if(v.begin(), v.end(), IsEqualToS);
    st = vectorToStack(v);
    if (i != v.end())
        cout << *(i) << endl;
    else
        cout << "The list has not the element." << endl;

    cout << "Delete the minimum element\n";
    v = stackToVector(st);

    i = min_element(v.begin(), v.end());
    s = *i;

    i = remove_if(v.begin(), v.end(), IsEqualToS);
    v.erase(i, v.end());

    st = vectorToStack(v);
    PrintStack(st);

    cout << "Division" << endl;
    v = stackToVector(st);
    i = max_element(v.begin(), v.end());

    s = *i;
    for_each(v.begin(), v.end(), DeleteMoney);

    st = vectorToStack(v);
    PrintStack(st);
}