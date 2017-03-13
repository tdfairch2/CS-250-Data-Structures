#include "List.hpp"

List::List()
{
	m_itemCount = 0;
	m_arraySize = 3;
}

void List::Insert(string newItem, int position)
{
	m_data[position] = newItem;
}

void List::Delete(int position)
{
	m_data[position] = "";
}

string List::GetItem(int position)
{
	return m_data[position];
}