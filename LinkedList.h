#pragma once
#pragma once
#include "Interfaces.h"
#include "LinkedContainerIter.h"
template<class T>
class LinkedList :
	public  virtual InsertableContainer<T>,
	public virtual PushPopContainer<T> {
private:
	TwoLinkNode<T> *bot, *top;
	int size;
public:
	friend LinkedContainerIter<T, LinkedList<T>, TwoLinkNode<T>>;
	friend LinkedContainerIter<T const, const LinkedList<T>, TwoLinkNode<T>>;
	LinkedList();
	LinkedList(const T& value);
	LinkedList(const LinkedList<T>&);
	LinkedList<T>& operator=(const LinkedList<T>&);
	JavaIteratorInterface<T&>* CreateIter();
	JavaIteratorInterface<const T&>* CreateConstIter() const;
	int Size() const;
	bool IsEmpty() const;
	bool Push(const T&);
	T Pop();
	T& Peek();
	T& Get(int index) const;
	void Set(int, const T&);
	bool Insert(int, const T&);
	T Remove(int);
	~LinkedList();
};
template<class T>
LinkedList<T>::LinkedList() {
	bot = NULL;
	top = NULL;
	size = 0;
}
template<class T>
LinkedList<T>::LinkedList(const T& value) 
{
	TwoLinkNode<T> *val = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Prev = newNode->Next = NULL;
	top = bot = newNode;
	size = 1;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) 
{
	TwoLinkNode<T> * newNode = other.top;
	size = 0;
	while (newNode) {
		this->Push(newNode->value);
		newNode = newNode->Next;
	}
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) 
{
	TwoLinkNode<T> *newNode;
	while (top) {
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
JavaIteratorInterface<T&>* LinkedList<T>::CreateIter() 
{ 
	return new LinkedContainerIter<T, LinkedList<T>, TwoLinkNode<T>>(this); 
}

template<class T>
JavaIteratorInterface<T const&>* LinkedList<T>::CreateConstIter() const 
{ 
	return new LinkedContainerIter<T const, const LinkedList<T>, TwoLinkNode<T>>(this); 
}
template<class T>
int LinkedList<T>::Size() const 
{
	return size;
}
template<class T>
bool LinkedList<T>::IsEmpty() const 
{
	return size == 0;
}

template<class T>
bool LinkedList<T>::Push(const T& value) 
{
	TwoLinkNode<T> *newNode = new TwoLinkNode<T>;
	newNode->value = value;
	newNode->Prev = bot;
	newNode->Next = NULL;
	if (IsEmpty())
		top = newNode;
	else
		bot->Next = newNode;
	bot = newNode;
	size++;
	return true;

}
template<class T>
T LinkedList<T>::Pop() 
{
	assert(!IsEmpty());
	T valueForReturn = bot->value;
	TwoLinkNode<T> *newBotNode = bot->Prev;
	delete bot;
	bot = newBotNode;
	size--;
	return valueForReturn;
}
template<class T>
T& LinkedList<T>::Peek() 
{
	return top->value;
}
template<class T>
T& LinkedList<T>::Get(int index) const 
{
	assert(!(IsEmpty() || index >= size || index < 0));
	TwoLinkNode<T> *forGetNode = bot;
	for (int i = 1; i <= size - 1 - index; i++)
		forGetNode = forGetNode->Next;
	return forGetNode->value;
}
template<class T>
void LinkedList<T>::Set(int index, const T& value) 
{
	assert(!(IsEmpty() || index >= size || index < 0));
	TwoLinkNode<T> *forSetNode = top;
	for (int i = 1; i <= size - 1 - index; i++)
		forSetNode = forSetNode->Next;
	forSetNode->value = value;
}
template<class T>
bool LinkedList<T>::Insert(int index, const T& value) 
{
	if (index > size || index < 0 || IsEmpty() && index != 0)
		return false;
	Push(value);
	T swapValue;
	for (int i = size - 1; i > index; i--) {
		swapValue = Get(i - 1);
		Set(i - 1, Get(i));
		Set(i, swapValue);
	}
	return true;
}
template<class T>
T LinkedList<T>::Remove(int index) 
{
	if (index >= size || index < 0 || IsEmpty())
		throw 2;
	T newNodeDel = Pop();
	for (int i = index; i < size - 1; i++)
		Set(i, Get(i + 1));
	if (index != size)
		Set(size - 1, newNodeDel);
	return 0;
}

template<class T>
LinkedList<T>::~LinkedList() 
{
	TwoLinkNode<T> *nodeForDel;
	for (int i = 0; top && i < Size(); i++)
	{
		nodeForDel = top->Next;
		delete top;
		top = nodeForDel;
	}
}

