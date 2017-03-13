#include "List.hpp"
#include <exception>

List::List()
{
	m_itemCount = 0;
	m_arraySize = 3;
}

void List::Insert(string newItem, int position)
{
	if (position > 2)
	{
		throw out_of_range("Invalid choice, try again: " + position);
	}
	m_data[position] = newItem;
}


void List::Delete(int position)
{
	if (position > 2)
	{
		throw out_of_range("Invalid choice, try again: " + position);
	}
	m_data[position] = position;
}

string List::GetItem(int position)
{
	return m_data[position];
}