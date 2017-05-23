#pragma once
#include "Interfaces.h"
#include "StaticArrayIter.h"
#include <string>
#include <cassert>
template<class T>
class StaticArray :
	public IndexedContainer<T> 
{
private:
	T *arr, defaultValue;
	int size;
public:
	friend StaticArrayIter<T, StaticArray<T>>;
	friend StaticArrayIter<const T, const StaticArray<T>>;
	StaticArray(int, const T&);
	StaticArray(const StaticArray<T>&);
	StaticArray<T>& operator=(const StaticArray<T>&);
	
	JavaIteratorInterface<T&>* CreateIter();
	JavaIteratorInterface<const T&>* CreateConstIter() const;
	int Size() const;
	bool IsEmpty() const;
	
	T& Get(int) const;
	void Set(int, const T&);
	~StaticArray();
};
template<class T>
JavaIteratorInterface<T&>* StaticArray<T>::CreateIter() 
{ 
	return new StaticArrayIter<T, StaticArray<T>>(this); 
}
template<class T>
JavaIteratorInterface<T const&>* StaticArray<T>::CreateConstIter() const
{ 
	return new StaticArrayIter<const T, const StaticArray<T>>(this); 
}
template<class T>
StaticArray<T>::StaticArray(int size, const T& defaultValue) 
{
	this->size = size;
	this->defaultValue = defaultValue;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = defaultValue;
}
template<class T>
StaticArray<T>::StaticArray(const StaticArray<T>& second) 
{
	this->size = second.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
	this->arr[i] = second.arr[i];
}
template<class T>
StaticArray<T>& StaticArray<T>::operator=(const StaticArray<T>& second) 
{
	delete[] arr;
	this->size = second.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		this->arr[i] = second.arr[i];
}
template<class T>
int StaticArray<T>::Size() const
{
	return size;
}
template<class T>
bool StaticArray<T>::IsEmpty() const 
{
	return size == 0;
}
template<class T>
T& StaticArray<T>::Get(int index) const 
{
	assert(!(index >= size || index < 0));
	return arr[index];
}
template<class T>
void StaticArray<T>::Set(int index, const T& value) 
{
	assert(!(index >= size || index < 0));
	arr[index] = value;
}
template<class T>
StaticArray<T>::~StaticArray() 
{
	delete[] arr;
}

