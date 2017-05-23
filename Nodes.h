#pragma once
template<class T>
struct OneLinkNode 
{
	T value;
	OneLinkNode *Next;
};
template<class T>
struct TwoLinkNode 
{
	T value;
	TwoLinkNode *Prev, *Next;
};


