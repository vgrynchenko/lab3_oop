#pragma once
#include "Interfaces.h"
#include "LinkedContainerIter.h"
#include <string>
#include <cassert>
#include <iostream>
template<class T>
class Stack :
	public PushPopContainer<T> 
{
private:
	TwoLinkNode<T> *top, *bot;
	int size;
public:
	Stack();
	friend LinkedContainerIter<T, Stack<T>, TwoLinkNode<T>>;
	friend LinkedContainerIter<T const, const Stack<T>, TwoLinkNode<T>>;
	JavaIteratorInterface<T&>* CreateIter();
	JavaIteratorInterface<const T&>* CreateConstIter() const;
	Stack(const T& value);
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	int Size() const;
	bool IsEmpty() const;
	bool Push(const T&);
	T Pop();
	T& Peek();
	~Stack();
};
template<class T>
JavaIteratorInterface<T&>* Stack<T>::CreateIter() 
{ 
	return new LinkedContainerIter<T, Stack<T>, TwoLinkNode<T>>(this); 
}

template<class T>
JavaIteratorInterface<T const&>* Stack<T>::CreateConstIter() const 
{ 
	return new LinkedContainerIter<T const, const Stack<T>, TwoLinkNode<T>>(this); 
}
template<class T>
Stack<T>::Stack() 
{
	top = NULL;
	bot = NULL;
	size = 0;
}
template<class T>
Stack<T>::Stack(const T& value) 
{
	TwoLinkNode<T> * newNode = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Next = newNode->Prev= NULL;
	top = bot = newNode;
	size = 1;
}

template<class T>
Stack<T>::Stack(const Stack<T>& other) 
{
	TwoLinkNode<T> * newNode = other.bot;
	size = 0;
	while (newNode) 
	{
		this->Push(newNode->value);
		newNode = newNode->Prev;
	}
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) 
{
	TwoLinkNode<T> * newNode;
	while (top) 
	{
		newNode = top->Next;
		delete top;
		top = newNode;
	}
	newNode = other.bot;
	size = 0;
	while (newNode) 
	{
		this->Push(newNode->value);
		newNode = newNode->Prev;
	}
	return *this;
}
template<class T>
int Stack<T>::Size() const 
{
	return size;
}
template<class T>
bool Stack<T>::IsEmpty() const 
{
	return size == 0;
}
template<class T>
bool Stack<T>::Push(const T&value) 
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
T Stack<T>::Pop() 
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
T& Stack<T>::Peek() 
{
	return top->value;
}

template<class T>
Stack<T>::~Stack() 
{
	TwoLinkNode<T> *nodeForDel;
	for (int i = 0; top && i < Size(); i++) 
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
}



