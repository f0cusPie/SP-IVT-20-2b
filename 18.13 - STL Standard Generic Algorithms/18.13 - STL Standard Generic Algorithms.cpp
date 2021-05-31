#include <iostream>
#include <iterator>
#include <list>
#include "Pair.h"
#include <set>
#include <queue>
#include <time.h>
using namespace std;

void Print(list<Pair> l)
{
    list<Pair>::iterator it = l.begin();
    for (; it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Print(priority_queue<int> qu)
{
    for (int i = qu.size(); i > 0; i--)
    {
        cout << qu.top() << " ";
        qu.pop();
    }
    cout << endl;
}

void Print(multiset<int> col)
{
    multiset<int>::iterator it = col.begin();
    for (; it != col.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void Task1()
{
    // create
    list<Pair> col;
    for (int i = 0; i < 10; i++)
    {
        Pair newEl(rand() % 10, rand() % 100 / 10.0);
        col.push_back(newEl);
    }
    cout << "Создание списка" << endl;
    Print(col);

    // count
    Pair sum(0, 0);
    list<Pair>::iterator it = col.begin();
    for (it = col.begin(); it != col.end(); it++)
    {
        sum = sum + *it;
    }
    sum = sum / col.size();

    col.push_back(sum);

    cout << "Добавлено ср. арифм. в конец" << endl;
    Print(col);
}

void Task2()
{
    priority_queue<int> qu;

    // creation
    int size = 0;
    while (size < 1)
    {
        cout << "Введите размер очереди ";
        cin >> size;
    }
    cout << "Введите элементы" << endl;
    for (int i = 0; i < size; i++)
    {
        int newEl;
        cin >> newEl;
        qu.push(newEl);
    }
    cout << "Исходная очередь" << endl;
    Print(qu);

    // input data and key
    int a = -5, b = 0;
    while (a < 0 || b < a || b >= qu.size())
    {
        cout << "Введите интервал ";
        cin >> a >> b;
    }

    int key;
    cout << "Введите ключ ";
    cin >> key;

    // ===searching===
    priority_queue<int> newQu;
    // go to a
    for (int i = 0; i < a; i++)
    {
        newQu.push(qu.top());
        qu.pop();
    }
    // transfer of elements satisfying the condition
    for (int i = a; i <= b; i++)
    {
        if (qu.top() != key)
        {
            newQu.push(qu.top());
        }
        qu.pop();
    }
    // from b to end
    for (int i = 0; i <= qu.size(); i++)
    {
        newQu.push(qu.top());
        qu.pop();
    }
    qu = newQu;
    cout << "После удаление ключа в интервале" << endl;
    Print(qu);
}

void Task3()
{
    multiset<int> col;

    for (int i = 0; i < 10; i++)
        col.insert(col.begin(), rand() % 100);

    cout << "Исходный словарь" << endl;
    Print(col);

    int sum = *col.begin() + *(--col.end());

    multiset<int> newCol;
    multiset<int>::iterator it = col.begin();
    for (; it != col.end(); it++)
    {
        newCol.insert(*it + sum);
    }
    col = newCol;

    cout << "Добавлена сумма max и min элементов" << endl;
    Print(col);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    Task1();
    cout << endl << endl;
    Task2();
    cout << endl << endl;
    Task3();
}