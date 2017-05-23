#pragma once
#include "JavaIteratorInterface.h"
#include "LinkedContainerIter.h"
template <class T, class LinkedContainer, class Nodes>
class LinkedContainerIter :
	public JavaIteratorInterface<T&> 
{
private: Nodes *Iter;
public:
	LinkedContainerIter(LinkedContainer*);
	T& Next();
	bool hasNext() const;
	~LinkedContainerIter() {};
};
template <class T, class LinkedContainer, class Nodes>
LinkedContainerIter<T, LinkedContainer, Nodes>::LinkedContainerIter(LinkedContainer *ContIter)
{
	Iter = new Nodes;
	Iter->Next = ContIter->top;
}
template <class T, class LinkedContainer, class Nodes>
T& LinkedContainerIter<T, LinkedContainer, Nodes>::Next()
{
	if (hasNext())
	{
		Iter = Iter->Next;
		return Iter->value;
	}
	else
		throw 1;
}
template<class T, class LinkedContainer, class Nodes>
bool LinkedContainerIter<T, LinkedContainer, Nodes>::hasNext() const
{
	if (Iter != NULL)
		return Iter->Next;
	else
		return false;
}
