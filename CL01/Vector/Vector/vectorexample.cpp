#include <iostream>
#include <vector>

using namespace std;

int main()

{
	int myNumbers[3];
	myNumbers[0] = 2;
	myNumbers[1] = 3;
	myNumbers[2] = 6;

	for (int i = 0; i < 3; i++)
	{
		cout << i << "=" << myNumbers[i] << endl;
	}

	vector<int> myNumbers2;
	myNumbers2.push_back(2);
	myNumbers2.push_back(3);
	myNumbers2.push_back(6);

	for (int i = 0; i < myNumbers2.resize()); i++;
	{
		cout << i << "=" << myNumbers2[i] << endl;

	}

	return 0;
}