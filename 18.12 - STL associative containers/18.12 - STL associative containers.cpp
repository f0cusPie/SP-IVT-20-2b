#include <algorithm>
#include <iostream>
#include <iterator>
#include "List.h"
#include <set>
#include "Pair.h"
#include <time.h>
using namespace std;

bool operator<(Pair a, Pair b)
{
    return a.GetFirstElement() + a.GetSecondElement() < b.GetFirstElement() + b.GetSecondElement();
}

void Task1()
{
    // creation    
    multiset<double> storage;
    for (int i = 0; i < 10; i++)
    {
        storage.insert(rand() % 1000 / 10.0);
    }

    // print
    cout << "Task1" << endl << "Source dictionary" << endl;
    copy(storage.begin(), storage.end(), ostream_iterator<double>(cout, " "));
    cout << endl;

    // count
    multiset<double>::iterator it;
    double sum = 0;
    for (it = storage.begin(); it != storage.end(); it++)
    {
        sum += *it;
    }

    sum /= 10;
    cout << "Average = " << sum << endl;
    storage.insert(sum);

    // print
    copy(storage.begin(), storage.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
}

void Task2()
{
    // creation    
    multiset<Pair> storage;
    for (int i = 0; i < 10; i++)
    {
        Pair newElement;
        storage.insert(newElement);
    }

    // print
    multiset<Pair>::iterator it;
    cout << "Task2" << endl << "Source dictionary" << endl;
    for (it = storage.begin(); it != storage.end(); it++)
        cout << *it << " ";
    cout << endl;

    // get key
    Pair key;
    cout << "Enter the item you want to remove" << endl;
    cin >> key;

    // erasing
    storage.erase(key);

    // print
    for (it = storage.begin(); it != storage.end(); it++)
        cout << *it << " ";
    cout << endl;
}

template <typename T>
ostream& operator<<(ostream& stream, List<T> list)
{
    for (int i = 0; i < list.Size(); i++)
        stream << list[i] << " ";
    return stream;
}

void Task3()
{
    cout << "Task3";
    int arrToCopy[] = { 4,5,6,7,8,9,3,1,5,7 };
    List<int> storage(10, arrToCopy);

    cout << storage << endl;

    storage.AddToEachElement(storage.GetMax() + storage.GetMin());

    cout << storage << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    Task1();
    cout << endl;
    Task2();
    cout << endl;
    Task3();
}