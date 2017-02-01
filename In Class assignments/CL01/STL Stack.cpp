#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Book
{
public:
	Book(const string& title)
	{
		m_title = title;
		m_checkedIn = false;
	}

	void CheckIn()
	{
		cout << "Checked in \"" << m_title << "\"" << endl;
		m_checkedIn = true;
	}

private:
	string m_title;
	bool m_checkedIn;
};

int main()
{
	// Create a stack of Book objects called bookDrop.
	stack<Book> bookDrop;

	// Push a series of books into the bookDrop.   

	vector<Book> bookPool;
	//list<Student> students;

	bookPool.push_back(Book("The Wrong Side of Goodbye"));
	bookPool.push_back(Book("50 Hues of Mauve"));
	bookPool.push_back(Book("Cry, Cry Again"));
	bookPool.push_back(Book("The Rooster Crows at Midnight"));
	bookPool.push_back(Book("The Darker the Berry, The Sweeter the Drank"));
	bookPool.push_back(Book("Data Structures Made Easy... no, really!"));

	// Go through the stack of books using a while loop,
	// while the stack is not empty...
	// Take the top-most book, and push it into the bookPool.
	// Then pop the top book off the bookDrop.
	while (!bookDrop.empty())
	{
		bookDrop.top().CheckIn();
		bookPool.push_back(bookDrop.top());
		bookDrop.pop();
	}

	return 0;
}