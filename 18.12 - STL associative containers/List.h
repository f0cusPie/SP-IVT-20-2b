#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include "List.cpp"
using namespace std;

template <typename T>
class List
{
private:
	multiset<T> _storage;
public:
	List(int size, T* arr);

	T GetMax();

	T GetMin();

	void AddToEachElement(T element);

	int Size();

	T operator[](int ind);

	//friend ostream& operator<<(ostream& stream, List list);
};


