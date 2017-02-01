#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	float balance = 0.0;
	// Create a queue of floats, named transactions
	queue<float>transactions3;



	// Push some + and - floats into the transactions queue.
	transactions3.push(10.00);
	transactions3.push(-5.00);
	transactions3.push(7.50);

	// Loop through all the transactions - while the queue is empty.
	// Within the loop, whatever amount is at the front of the queue,
	// add it to the balance and then pop it off the queue.
	while (!transactions3.empty () )
	{
		float amount = transactions3.front();
		cout << amount << "was put into account" << endl;
		balance = balance + amount;
		transactions3.pop();
	}


	cout << "Final balance: $" << balance << endl;

	return 0;
}