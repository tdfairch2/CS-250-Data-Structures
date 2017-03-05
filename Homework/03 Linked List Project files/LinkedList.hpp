#ifndef _LINKED_LIST_HPP
#define _LINKED_LIST_HPP

#include <iostream>
#include <string>
using namespace std;


//Hey, Rachel
//Thanks so much for the in class assistance on this project
//Pretty much everything that's here is what you gave us 
//Whatever is missing (and let's face it, that's a lot).... well, that's all me!

//But I think I'm stating the obvious


template <typename T>
struct Node
{
    Node()
    {
        ptrNext = nullptr;
        ptrPrev = nullptr;
    }

    Node<T>* ptrNext;
    Node<T>* ptrPrev;

    T data;
};

template <typename T>
class LinkedList
{
    public:
    LinkedList()
    {
        m_ptrFirst = nullptr;
        m_ptrLast = nullptr;
        m_itemCount = 0;
    }

    ~LinkedList()
    {
        Free();
    }

    void Push( const T& newItem )
    {
		Node<T>* newNode = new Node<T>;
		newNode->data = newItem;

		if (m_ptrFirst == nullptr)
		{
			//List IS empty!
			m_ptrFirst = newNode;
			m_ptrLast = newNode;
		}

		else
		{
			//List is not empty

			newNode->ptrPrev = m_ptrLast;
			m_ptrLast->ptrNext = newNode;
			m_ptrLast = newNode;
		}
		m_itemCount++;
    }

	//Memory Allocation
    bool Insert( int index, const T& newItem )
    {
		Node<T>* ptrNew = new Node<T>;
		ptrNew->data = newItem;
        return true;
    }

    void Extend( const LinkedList& other )
    {
		Node<T>* ptrCurrent = other.m_ptrFirst;
    }

    bool Pop()
    {
		if (IsEmpty())
		{
			return false;
		}

		if (Size() > 1)
		{
			Node<T>* ptrPenultimate = m_ptrLast->ptrPrev;
			delete m_ptrLast;
			m_ptrLast = ptrPenultimate;
			m_ptrLast->ptrNext = nullptr;
			m_itemCount--;
			return true;

		}
		else
		{
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;
			return true;
		}
	}


    bool Remove( int index )
    {
        return false; // temp
    }

    T Get( int index ) const
    {
		// Error checking - invalid indices
		if (index < 0 || index >= m_itemCount)
		{
			return T();
		}

		Node<T>* ptrCurrent = m_ptrFirst;
		int counter = 0;

		//Traverse the list til we get to position "index"
		while (counter < index)
		{
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}
		//Return the data at this position
		return ptrCurrent->data;
    }

    int Size() const // done
    {
        return m_itemCount;
    }

    bool IsEmpty() const // done
    {
        return ( m_ptrFirst == nullptr );
    }

    T operator[]( int index ) // done
    {
        return Get( index );
    }

    LinkedList& operator=( const LinkedList& other )
    {
        return (*this); // temp
    }

    bool operator==( const LinkedList& other )
    {
        return false; // temp
    }

    bool operator!=( const LinkedList& other )
    {
        return !( (*this) == other );
    }

    private:
    void Free() // done
    {
        while ( !IsEmpty() )
        {
            Pop();
        }
    }

    Node<T>* m_ptrFirst;
    Node<T>* m_ptrLast;
    int m_itemCount;
};

#endif
