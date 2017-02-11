#include "SmartStaticArray.hpp"

SmartStaticArray::SmartStaticArray()
{
	m_itemCount = 0;
}

bool SmartStaticArray::Push(const string& newItem)
{
	if (m_itemCount == MAX_SIZE)
	{
		return false;
	}
	m_data[m_itemCount] = newItem;
	m_itemCount++;
}

bool SmartStaticArray::Insert(int index, const string& newItem)
{
	for (int i = m_itemCount - 1; i > index; i--)
	{
		if (m_itemCount == MAX_SIZE || m_itemCount < 0)
		{
			return false;
		}
		m_data[m_itemCount] = newItem;
	}
	return true;
}

bool SmartStaticArray::Extend(const SmartStaticArray& other)  // hard
{
	if (m_itemCount == MAX_SIZE)
	{
		return false;
	}
	// other.Size()
	for (int i = other.Size(); i > 0; i --)
	{
		m_data[m_itemCount - 1] = other.Get(i);
	}
	return true;
}

/*
INPUT: None
OUTPUT: True on succes, False on failure

This function will remove the item at the very end of the array.

Lazy-deletion: You don't actually have to remove the item; you just have to adjust m_itemCount.

If the array is empty, return false and don't do anything. Otherwise, return true.
*/
bool SmartStaticArray::Pop()
{
	//while (!m_data[m_itemCount].empty())
	//{
	//	m_data[m_itemCount].pop_back();
	//}
	return false; // temp
}

bool SmartStaticArray::Remove(int index) // hard
{

	if (index > MAX_SIZE || index < 0)
	{
		return false;
	}
	bool removeData = !IsEmpty() && (index > -1);
	if (removeData)
	{
		m_itemCount--;
		m_data[index] = m_data[m_itemCount];
	}

	return true;
}

/*
INPUT: Index of item to access
OUTPUT: Value of the item accessed

Return the value of the item at the index given.

If the index is invalid, return an empty string instead. ""

string m_data[MAX_SIZE];
m_data[0], m_data[1], ...
*/
string SmartStaticArray::Get(int index) const
{
	//return get(index); // temp
	return ""; // temp
}

int SmartStaticArray::Size() const
{
	return m_data[m_itemCount].size();
}

/*
INPUT: None
OUTPUT: True if full, false if not full

m_itemCount vs. MAX_SIZE
*/
bool SmartStaticArray::IsFull() const
{
	while (!m_data[m_itemCount].IsFull())
	{
		return false;
	}
}

/*
INPUT: None
OUTPUT: True if empty, false if not empty

Checking m_itemCount
*/
bool SmartStaticArray::IsEmpty() const
{
	while (!m_data[m_itemCount].IsEmpty())
	{
		return false;
	}
}

// Use Get( int )
string SmartStaticArray::operator[](int index)
{
	return "temp"; // temp
}

/*
INPUT: A second array
OUTPUT: A reference to the this array

Set the this array equal to the second array's values.

Iterate through all the items of the second array, copying the values over to the this array.

Make sure to also update the m_itemCount.

Return a reference to *this afterward.
*/
SmartStaticArray& SmartStaticArray::operator=(const SmartStaticArray& other) // hard	
{
	SmartStaticArray blorp; // temp
	return blorp; // temp
}

bool SmartStaticArray::operator!=(const SmartStaticArray& other)
{
	return !(*this == other);
}

/*
INPUT: A second array
OUTPUT: True if the second array is the same as this, or False if not.

Iterate through all elements of both arrays and compare the values.

If they are equivalent, then return true.

Otherwise, return false.

for loop
*/
bool SmartStaticArray::operator==(const SmartStaticArray& other)
{
	return false; // temp
}
