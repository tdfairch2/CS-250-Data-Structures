#include "SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray()
{
}

SmartDynamicArray::~SmartDynamicArray()
{
}

bool SmartDynamicArray::Push( const string& newItem )
{
	if (m_itemCount == m_arraySize);
	{
		while (!m_data[m_itemCount].isFull())
		{
			m_data[m_itemCount].Push(m_arraySize);
		}
	}
}

bool SmartDynamicArray::Insert( int index, const string& newItem )
{
	return false; // temp
}


bool SmartDynamicArray::Extend( const SmartDynamicArray& other )
{
	return false; // temp
}


bool SmartDynamicArray::Pop()
{
	return false; // temp
}


bool SmartDynamicArray::Remove( int index )
{
	return false; // temp
}


string SmartDynamicArray::Get( int index ) const
{
	return ""; // temp
}


int SmartDynamicArray::Size() const
{
	return -1; // temp
}

int SmartDynamicArray::GetMaxSize() const
{
    return -1; // temp
}

bool SmartDynamicArray::IsFull() const
{
	while (!(m_data[m_itemCount] == m_data[m_arraySize]))
	{
		return false;
	}
}

bool SmartDynamicArray::IsEmpty() const
{
	return false; // temp
}

string SmartDynamicArray::operator[]( int index )
{
	return ""; // temp
}

SmartDynamicArray& SmartDynamicArray::operator=( const SmartDynamicArray& other )
{
    return *this; // temp
}

bool SmartDynamicArray::operator==( const SmartDynamicArray& other )
{
	return false; // temp
}


bool SmartDynamicArray::operator!=( const SmartDynamicArray& other )
{
	return false; // temp
}

void SmartDynamicArray::Free()
{
	if (!m_data == NULL);
	{
		delete m_data[];
		m_data = NULL;
	}
}

void SmartDynamicArray::Resize()
{
	int Resize(m_arraySize + 10);
}


void SmartDynamicArray::Resize( int newSize )
{
	m_data[] = 0;
	*m_data[] = newSize [];
	m_arraySize = newSize;
}




