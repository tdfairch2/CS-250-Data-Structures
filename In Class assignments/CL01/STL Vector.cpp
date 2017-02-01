#include <iostream>
#include <vector>
#include <string>
using namespace std;

void AddIngredients(vector<string>& ingredients)
{
	// Use the push_back function to add "lettuce", "tomato", "mayo", "mustard", and "bread" to the vector.
	vector <string> ingredients5;
	ingredients5.push_back("lettuce");
	ingredients5.push_back("tomato");
	ingredients5.push_back("mayo");
	ingredients5.push_back("mustard");
	ingredients5.push_back("bread");
}

void DisplayIngredients(const vector<string>& ingredients)
{
	// Use a for-loop, going from 0 to the ingredient's size(), to display each of the ingredients
	for (int i = 0; i < 4; i++)
	{
		cout << i << "=" << ingredients[i] << endl;
	}
}

int main()
{
	// 1. Declare a vector of strings named ingredients.
	vector <string> ingredients[5];



	// 2. Call the AddIngredients function, passing in ingredients as an argument.
	vector <string> AddIngredients[5];


	// 3. Call the DisplayIngredients function, passing in ingredients as an argument.
	vector <string> DisplayIngredients[5];


	return 0;
}
