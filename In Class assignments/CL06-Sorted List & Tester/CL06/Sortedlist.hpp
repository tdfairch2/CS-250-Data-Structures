#ifndef _SORTEDLIST_HPP
#define _SORTEDLIST_HPP


#include <iostream>


class Tester;
template <typename T>

class Node
{
public:
	T data;
	Node<T>* ptrNext;
	Node<T>* ptrPrevious;
};


template <typename T>
class Sortedlist
{

public:
	void Push(T data)
	{

	}
	int GetAt(T data)
	{
		return 0;
	}

private:
	T data;
	Node<T>* ptrFirst;
	Node<T>* ptrLast;

	friend class Tester;
};

#endif