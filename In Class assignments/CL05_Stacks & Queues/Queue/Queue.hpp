#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "../DoublyLinkedList.hpp"

template <typename T>
class Queue : public DoublyLinkedList<T>
{
    public:
    Queue()
        : DoublyLinkedList<T>()
    {
    }

    virtual ~Queue()
    {
    }

    virtual void Push( T data )
    {
		DoublyLinkedList<T>::PushFront(data);
    }

    virtual void Pop(T data)
    {
		DoublyLinkedList<T>::PopFront(data);
    }

    virtual T Take(T data)
    {
		DoublyLinkedList<T>::GetFront(data);
		Return;
    }
};

#endif
