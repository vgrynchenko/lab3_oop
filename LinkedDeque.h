#pragma once
#include "Interfaces.h"
#include "LinkedContainerIter.h"
template<class T>
class LinkedDeque :
	public Deque<T> {
private:
	TwoLinkNode<T> *bot, *top;
	int size;
public:
	friend LinkedContainerIter<T, LinkedDeque<T>, TwoLinkNode<T>>;
	friend LinkedContainerIter<T const, const LinkedDeque<T>, TwoLinkNode<T>>;
	LinkedDeque();
	LinkedDeque(const T& value);
	LinkedDeque(const LinkedDeque<T>&);
	LinkedDeque<T>& operator=(const LinkedDeque<T>&);
	JavaIteratorInterface<T&>* CreateIter();
	JavaIteratorInterface<const T&>* CreateConstIter() const;

	int Size() const;
	bool IsEmpty() const;
	bool PushFront(const T& value);
	bool PushBack(const T&value);
	T PopFront();
	T PopBack();
	T& PeekFront();
	T& PeekBack();
	~LinkedDeque();
};
template<class T>
LinkedDeque<T>::LinkedDeque()
{
	bot = NULL;
	top = NULL;
	size = 0;
}
template <class T>
LinkedDeque<T>::LinkedDeque(const T& value) 
{
	TwoLinkNode<T> *newNode = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Next = newNode->Prev = NULL;
	top = bot = newNode;
	size = 1;
}
template<class T>
LinkedDeque<T>::LinkedDeque(const LinkedDeque<T>& other) 
{
	TwoLinkNode<T> * newNode = other.top;
		size = 0;
		while (newNode) 
		{
			this->PushBack(newNode->value);
			newNode = newNode->Next;
		}
}

template<class T>
LinkedDeque<T>& LinkedDeque<T>::operator=(const LinkedDeque<T>& other) 
{
	TwoLinkNode<T> *newNode;
	while (top) 
	{
		newNodep = top->Next;
		delete top;
		top = newNode;
	}
		newNode = other.top;
		size = 0;
	while (tmp) 
	{
		PushBack(newNode->value);
		newNode = newNode->Next;
	}
		return *this;
}
template<class T>
int LinkedDeque<T>::Size() const 
{
	return size;
}
template<class T>
bool LinkedDeque<T>::IsEmpty() const 
{
	return size == 0;
}
template<class T>
bool LinkedDeque<T>::PushFront(const T& value) 
{
	TwoLinkNode<T> *newNode = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Prev = NULL;
	newNode->Next = top;
	if (IsEmpty())
		bot = newNode;
	else
		top->Prev = newNode;
	top = newNode;
		size++;
	return true;
}
template<class T>
bool LinkedDeque<T>::PushBack(const T& value) 
{
	TwoLinkNode<T> *newNode = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Next = NULL;
	newNode->Prev = bot;
	if (IsEmpty())
		top = newNode;
	else
		bot->Next = newNode;
		bot = newNode;
		size++;
	return true;
}
template<class T>
T LinkedDeque<T>::PopFront() 
{
	assert(!IsEmpty());
	TwoLinkNode<T> *newHeadNode = top->Next;
	T valueForReturn = top->value;
	delete top;
	top = newHeadNode;
	if (top)
		top->Prev = NULL;
	else
		bot = NULL;
	size--;
	return valueForReturn;
}
template<class T>
T LinkedDeque<T>::PopBack() 
{
	assert(!IsEmpty());
	TwoLinkNode<T> *newHeadNode = bot->Prev;
	T valueForReturn = bot->value;
	delete bot;
	bot = newHeadNode;
	if (bot)
		bot->Next = NULL;
	else
		top = NULL;
		size--;
	return valueForReturn;
}
template<class T>
T& LinkedDeque<T>::PeekFront() 
{
	return top->value;
}
template<class T>
T& LinkedDeque<T>::PeekBack() 
{
	return bot->value;
}
template<class T>
JavaIteratorInterface<T&>* LinkedDeque<T>::CreateIter() 
{ 
	return new LinkedContainerIter<T, LinkedDeque<T>, TwoLinkNode<T>>(this); 
}
template<class T>
JavaIteratorInterface<T const&>* LinkedDeque<T>::CreateConstIter() const 
{ 
	return new LinkedContainerIter<const T, const LinkedDeque<T>, TwoLinkNode<T>>(this);
}
template<class T>
LinkedDeque<T>::~LinkedDeque()
{
	TwoLinkNode<T> *nodeForDel;
	for (int i = 0; top&& i < Size(); i++)
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
}




