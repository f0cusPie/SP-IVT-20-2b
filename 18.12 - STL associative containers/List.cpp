#ifndef _LIST_CPP
#define _LIST_CPP

#include "List.h"
using namespace std;

template <typename T>
List<T>::List(int size, T* arr)
{
	_storage.clear();

	for (int i = 0; i < size; i++)
	{
		_storage.insert(arr[i]);
	}
}

template <typename T>
T List<T>::GetMax()
{
	multiset<T>::template iterator it = _storage.end();
	it--;
	return *it;
}

template <typename T>
T List<T>::GetMin()
{
	return *_storage.begin();
}

template <typename T>
void List<T>::AddToEachElement(T element)
{
	multiset<T> newCollection;

	for_each(_storage.begin(), _storage.end(), [=, &newCollection](T el) -> void {
		newCollection.insert(el + element); });

	_storage = newCollection;
}

template <typename T>
int List<T>::Size()
{
	return _storage.size();
}

template <typename T>
T List<T>::operator[](int ind)
{
	multiset<T>::template iterator it = _storage.begin();
	for (int i = 0; i < ind && it != _storage.end(); i++)
		it++;
	return *it;
}

/*
template <typename T>
ostream& operator<<(ostream& stream, List<T> list)
{
	for (int i = 0; i < list.Size(); i++)
		stream << list[i] << " ";
	return stream;
}
*/

#endif