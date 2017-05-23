#pragma once
#include "Interfaces.h"
#include "LinkedContainerIter.h"
#include <cassert>
template<class T>
class Queue :
	public PushPopContainer<T> 
{
private:
	TwoLinkNode<T> *top, *bot;
	int size;
public:
	Queue();
	friend LinkedContainerIter<T, Queue<T>, TwoLinkNode<T>>;
	friend  LinkedContainerIter<T const, const Queue<T>, TwoLinkNode<T>>;
	Queue(const T& value);
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	JavaIteratorInterface<T&>* CreateIter();
	JavaIteratorInterface<const T&>* CreateConstIter() const;
	int Size() const;
	bool IsEmpty() const;
	bool Push(const T&);
	T Pop();
	T& Peek();
	~Queue();
};
template<class T>
JavaIteratorInterface<T&>* Queue<T>::CreateIter() 
{ 
	return new LinkedContainerIter<T, Queue<T>, TwoLinkNode<T>>(this); 
}

template<class T>
JavaIteratorInterface<T const&>* Queue<T>::CreateConstIter() const 
{ 
	return new LinkedContainerIter<T const, const Queue<T>, TwoLinkNode<T>>(this); 
}

template<class T>
Queue<T>::Queue() 
{
	top = NULL;
	bot = NULL;
	size = 0;
}
template<class T>
Queue<T>::Queue(const T& value)
{
	TwoLinkNode<T> * newNode = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Next = newNode->Prev = NULL;
	top= bot = newNode;
	size = 1;
}
template<class T>
Queue<T>::Queue(const Queue<T>& other) 
{
	TwoLinkNode<T> * newNode = other.top;
	size = 0;
	while (newNode) {
		this->Push(newNode->value);
		newNode = newNode->Next;
	}
}
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) 
{
	TwoLinkNode<T> * newNode;
	while (top) 
	{
		newNode = top->Next;
		delete top;
		top = newNode;
	}
	newNode = other.top;
	size = 0;
	while (newNode) {
		this->Push(newNode->value);
		newNode = newNode->Next;
	}
	return *this;
}
template<class T>
int Queue<T>::Size() const 
{
	return size;
}
template<class T>
bool Queue<T>::IsEmpty() const 
{
	return size == 0;
}
template<class T>
bool Queue<T>::Push(const T& value) 
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
T Queue<T>::Pop() 
{
	assert(!IsEmpty());
	T valueForReturn = top->value;
	TwoLinkNode<T> *newHeadNode = top->Next;
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
T& Queue<T>::Peek() 
{
	return top->value;
}

template<class T>
Queue<T>::~Queue() 
{
	TwoLinkNode<T> *nodeForDel;
	for (int i = 0; top && i < Size(); i++)
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
	
}
