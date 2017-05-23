#pragma once
#include "JavaIteratorInterface.h"

template <class T, class StaticArray>
class StaticArrayIter :
	public JavaIteratorInterface<T&> 
{
private:
	T * Iter;
	int SizeArr, CountIter;
public:
	StaticArrayIter(StaticArray *);
	T & Next();
	bool hasNext() const;
	~StaticArrayIter() {};
};
template<class T, class StaticArray>
StaticArrayIter<T, StaticArray>::StaticArrayIter(StaticArray *IterArr) 
{
	this->Iter = IterArr->arr;
	CountIter = 0;
	SizeArr = IterArr->Size ();
}
template <class T, class StaticArray>
T& StaticArrayIter<T, StaticArray>::Next()
{
	if (hasNext())
	{
		if (CountIter == 0)
		{
			CountIter++;
			return *Iter;
		}
		CountIter++;
		return *(Iter++);
	}
	else
		throw 1;
}
template <class T, class StaticArray>
bool StaticArrayIter<T, StaticArray>::hasNext() const
{
	return CountIter < SizeArr;
}