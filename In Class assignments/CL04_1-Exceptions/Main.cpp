#include <iostream>
#include <exception>
using namespace std;

#include "List.hpp"



void choice(int selection);

int main()
{
	List myList;

	string menu[] = { "Insert", "Delete", "Get Item" };

	while (true)
	{
		cout << endl << "-------------------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i << ". " << menu[i] << endl;
		}

		int choice;
		cout << "Which? ";
		cin >> choice;


		if (choice == 0)
		{
			int position;
			string newItem;

			cout << "Index: ";
			cin >> newItem;

			cout << "New value: ";
			cin >> position;

			try
			{
				myList.Insert(newItem, position);
			}
			catch (out_of_range ex)
			{
				cout << "Invalid! (Display error)" << endl;
			}

		}
		else if (choice == 1)
		{
			int position;

			cout << "Index: ";
			cin >> position;

			try
			{
				myList.Delete(position);
			}
			catch (const out_of_range& ex)
			{
				cout << "Invalid! (Display error)" << endl;
			}
			
		}
		else if (choice == 2)
		{
			int position;

			cout << "Index: ";
			cin >> position;

			try
			{
				myList.GetItem(position);
			}
			catch (const out_of_range& ex)
			{
				cout << "Invalid! (Display error)" << endl;
			}
			cout << position << endl;

		}
	}

	return 0;
}