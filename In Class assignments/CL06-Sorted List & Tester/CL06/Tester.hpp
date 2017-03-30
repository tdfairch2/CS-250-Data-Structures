
//Error thrown at 2nd test - "Size is not 1"
//Something is incorrect with 'GetAt' functionality
//I'm just not sure how to implement this

#ifndef _TESTER_HPP
#define _TESTER_HPP

#include "Sortedlist.hpp"

class Tester
{
public:
	void Start()
	{
		TestGetAt();
		TestPush();
		TestSize();
	}
private:
	bool TestGetAt()
	{
		Sortedlist<int> sl;
		//  GetAt( int index ) returns value at that index.
		//  0
		// [1]
		sl.Push(0);
		if (sl.GetAt(0) != 0)
			{
				cout << "Test failed: Size is not 0." << endl;
				return false;
			}

		// Test 2

		 // 0
		 //[3]
		Sortedlist<int> s2;
		s2.Push(1);
		if (s2.GetAt(1) != 1)
			{
				cout << "Test failed: Size is not 1." << endl;
				return false;
			}


		// Test 3
		//  0   1   2
		// [3] [4] [5]
		Sortedlist<int> s3;
		s3.Push(3);
		s3.Push(4);
		s3.Push(5);
		if (s3.GetAt(0) != 3)
			{
				cout << "Test failed: Size is not 3." << endl;
				return false;
			}

		cout << "All tests passed" << endl;
		return true;
	}
	
	bool TestPush()
	{
		return false;
	}

	bool TestSize()
	{
		return false;
	}

};
#endif

