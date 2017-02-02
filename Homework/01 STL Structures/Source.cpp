#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "Page.hpp"

void LoadPages(vector <string>& pages, const string& Aesop)
{
	ifstream input(Aesop);
	string line;
	string pageText = "";
	int lineCount = 0;
	int pageCount = 0;

	while (getline(input, line))
	{
		pageText = pageText + "\n" + line;

		lineCount++;
		if (lineCount == 27)
		{
			string newPageVariable = pageText;
			//following 3 lines were the originals
			// Add page to book now
			//pages[pageCount].text = pageText;
			//pageCount++;
			pages.push_back(newPageVariable);

			// Reset the page text
			pageText = "";

			// Reset the line count
			lineCount = 0;
		}

	}

	input.close();
}

		  //void ReadBook(Page pages[100])  This is the original code.  
		  //  
		  // Tried to set totalPages to get the vector's size,   
		  // as per the assignment instructions but I was unable.	
void ReadBook (Page pageCount)
{
	int currentPage = 0;
	Page totalPages = pageCount;

	bool done = false;

	while (!done)
	{
		pages[currentPage].Display();
		cout << "--- PAGE " << currentPage + 1 << " OF " << totalPages << "---------------------------------" << endl;
		cout << "(N)ext Page, (P)revious Page, (Q)uit" << endl;
		cout << ">> ";
		string choice;
		cin >> choice;

		if (choice == "Q" || choice == "q") 
		{ 
			done = true; 
		}
		else if (choice == "N" || choice == "n")
		{
			if (currentPage + 1 < totalPages)
			{
				currentPage++;
			}
		}
		else if (choice == "P" || choice == "p")
		{
			if (currentPage - 1 >= 0)
			{
				currentPage--;
			}
		}
	}
}

int main()
{
	 std::vector<int> pages;	//This is where I wanted to change the pages array to a vector
		// Page pages[100];		//Here is the original pages array

	LoadPages(pages, "Aesop.txt");
	ReadBook(pages);

	return 0;
}
