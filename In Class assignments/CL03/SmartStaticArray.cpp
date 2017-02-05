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


bool SmartStaticArray::Extend(const SmartStaticArray& other)
{
	if (m_itemCount == MAX_SIZE)
	{
		return false;
	}
	m_data[m_itemCount - 1] = other.Get;
}

bool SmartStaticArray::Pop()
{
	while (!m_data[m_itemCount].empty())
	{
		m_data[m_itemCount].pop_back();
	}
	return false; // temp
}

bool SmartStaticArray::Remove(int index)
{
	//The for loop is to start at the selected index and increment to the end of the array
	//removing array elements as it progresses
	for (int i = index; index != m_itemCount; i++) 
	{
		m_data[i + 1] = m_data[i];
		if (m_itemCount == MAX_SIZE || m_itemCount < 0)
		{
			return false;
		}
		//This is where I wanted to remove each next element but my logic is incorrect
		void remove (m_data[i]);
	}
	return true;
}

//This is where I'm prompting the user to choose a location
string SmartStaticArray::Get(int index) const
{
	cout << "What location do you want" << endl;
	cin >> index >> endl;
	return get(index); // temp
}


int SmartStaticArray::Size() const
{
	std::cout << m_data[m_itemCount].size();
	return -1; // temp
}


bool SmartStaticArray::IsFull() const
{
	while (!m_data[m_itemCount].full())
	{
		return true;
	}
	return -1; // temp
}


bool SmartStaticArray::IsEmpty() const
{
	while (!m_data[m_itemCount].empty())
	{
		return true;
	}
	return -1; // temp
}

string SmartStaticArray::operator[](int index)
{
	return "temp"; // temp
}


SmartStaticArray& SmartStaticArray::operator=(const SmartStaticArray& other)
{
	SmartStaticArray blorp; // temp
	return blorp; // temp
}

bool SmartStaticArray::operator!=(const SmartStaticArray& other)
{
	return !(*this == other);
}
