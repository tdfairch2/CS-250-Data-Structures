#include "Tester_SmartStaticArray.hpp"

void Tester_SmartStaticArray::Start()
{
	int testCount = 12;
	int score = 0;

	cout << "TESTS BEGIN..." << endl << endl;

	score += TestPush();
	score += TestInsert();
	score += TestExtend();
	score += TestPop();
	score += TestRemove();
	score += TestGet();
	score += TestSize();
	score += TestIsFull();
	score += TestIsEmpty();
	score += TestSubscriptOperator();
	score += TestAssignmentOperator();
	score += TestEqualityOperator();

	cout << endl << "RESULT: " << score << " OF " << testCount << endl;
}


bool Tester_SmartStaticArray::TestPush()
{
	bool allTestsPass = true;

	string testItems[6] = { "a", "b", "c", "d", "e", "f" };

	// Test 1: Fill array with items, make sure they're inserted properly.
	SmartStaticArray arr1;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr1.Push(testItems[i % 6]);
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		string result = arr1.Get(i);
		if (result != testItems[i % 6])
		{
			ReportFailure("TestPush()", "Expected item \"" + testItems[i % 6] + "\" but got \"" + result + "\" instead.");
			allTestsPass = false;
		}
	}


	// Test 2: Try to push too many items in array
	SmartStaticArray arr2;
	for (int i = 0; i < MAX_SIZE + 1; i++)
	{
		bool result = arr2.Push(testItems[i % 6]);

		if (i < MAX_SIZE && result == false)
		{
			ReportFailure("TestPush()", "Inserting items into array, return value was false even though input was valid.");
			allTestsPass = false;
		}

		else if (i >= MAX_SIZE && result == true)
		{
			ReportFailure("TestPush()", "Inserting items into FULL array, return value was true (success), but should have been false (fail).");
			allTestsPass = false;
		}
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestPush()" << endl;
	}

	return allTestsPass;
}


bool Tester_SmartStaticArray::TestInsert()
{
	bool allTestsPass = true;

	// Test 1: Test insert like a push
	SmartStaticArray arr1;
	arr1.Insert(0, "A");
	for (int i = 1; i < MAX_SIZE - 1; i++)
	{
		if (arr1.Insert(arr1.Size() - 1, "A") == false)
		{
			ReportFailure("TestInsert()",
				"Tried to insert items to the end of an array, failed for some reason.");
			allTestsPass = false;
		}
	}

	// Test 2: Test insert at various positions
	SmartStaticArray arr2, solutionArray;
	arr2.Push("A");
	arr2.Push("B");
	arr2.Push("C");
	arr2.Push("D");
	solutionArray.Push("A");  // 0
	solutionArray.Push("B");  // 1
	solutionArray.Push("Z");  // 2
	solutionArray.Push("C");  // 3
	solutionArray.Push("X");  // 4
	solutionArray.Push("D");  // 5

	arr2.Insert(3, "Z");
	arr2.Insert(4, "X");

	if (arr2.Size() != 6)
	{
		ReportFailure("TestInsert()",
			"Inserted 2 items into an array of size 4. Didn't return a Size() of 6.");
		allTestsPass = false;
	}

	if ((arr2 == solutionArray) == false)
	{
		ReportFailure("TestInsert()",
			"Array with inserts didn't have correct final form.");
		allTestsPass = false;
	}

	// Test 3: Insert at invalid index
	SmartStaticArray arr3;
	if (arr3.Insert(-1, "A") != false)
	{
		ReportFailure("TestInsert()",
			"Tried to insert value at -1. Didn't return a false.");
		allTestsPass = false;
	}

	if (arr3.Insert(MAX_SIZE, "A") != false)
	{
		ReportFailure("TestInsert()",
			"Tried to insert a value at MAX_SIZE. Didn't return a false.");
		allTestsPass = false;
	}

	// Test 4: Insert item at non-continguous point.
	SmartStaticArray arr4;
	arr4.Push("A");
	arr4.Push("B");
	arr4.Push("C");

	if (arr4.Insert(10, "D") != false)
	{
		ReportFailure("TestInsert()",
			"Tried to insert an item non-contiugously (at position 10 in an array with 3 items.) Should have returned false.");
		allTestsPass = false;
	}
	if (arr4.Size() == 4)
	{
		ReportFailure("TestInsert()",
			"After trying to insert item at non-contiguous index of array, Size() reflects add. Invalid inserts shouldn't modify the array.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestInsert()" << endl;
	}

	return allTestsPass;
}


bool Tester_SmartStaticArray::TestExtend()
{
	bool allTestsPass = true;

	// Test 1: Normal extend
	SmartStaticArray arr1, arr2, solutionArray;

	arr1.Push("1");
	arr1.Push("3");
	arr2.Push("2");
	arr2.Push("4");
	solutionArray.Push("1");
	solutionArray.Push("3");
	solutionArray.Push("2");
	solutionArray.Push("4");

	if (arr1.Extend(arr2) != true)
	{
		ReportFailure("TestExtend()",
			"Extend function returned false, but it should have returned true.");
		allTestsPass = false;
	}

	if ((arr1 == solutionArray) == false)
	{
		ReportFailure("TestExtend()",
			"Tried to extend an array. Resulting solution wasn't correct.");
		allTestsPass = false;
	}

	// Test 2: Extend but not enough space
	SmartStaticArray arr3, arr4;
	for (int i = 0; i < MAX_SIZE - 2; i++)
	{
		arr3.Push("hi");
		arr4.Push("bye");
	}

	if (arr3.Extend(arr4) != false)
	{
		ReportFailure("TestExtend()",
			"Tried to extend past the array size. Should have returned false, but returned true.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestExtend()" << endl;
	}

	return allTestsPass;
}


bool Tester_SmartStaticArray::TestPop()
{
	bool allTestsPass = true;

	// Test 1: Pop empty array
	SmartStaticArray arr1;
	if (arr1.Pop() != false)
	{
		ReportFailure("TestPop()",
			"Tried to pop from an empty array. Should have returned false, but returned true.");
		allTestsPass = false;
	}

	// Test 2: Fill array and pop
	SmartStaticArray arr2;
	string values[3] = { "c", "a", "t" };
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr2.Push(values[i % 3]);
	}

	if (arr2.Size() != MAX_SIZE)
	{
		ReportFailure("TestPop()",
			"Array's size after pushing MAX_SIZE items is not MAX_SIZE.");
		allTestsPass = false;
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (arr2.Pop() != true)
		{
			ReportFailure("TestPop()",
				"A Pop failed while emptying out a full array, even though it shouldn't have.");
			allTestsPass = false;
		}
	}

	if (arr2.IsEmpty() == false)
	{
		ReportFailure("TestPop()",
			"Popped all items from an array. IsEmpty is false, but should be true.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestPop()" << endl;
	}

	return allTestsPass;
}


bool Tester_SmartStaticArray::TestRemove()
{
	bool allTestsPass = true;

	// Test 1: Remove at invalid index
	SmartStaticArray arr1;

	if (arr1.Remove(0) != false)
	{
		ReportFailure("TestRemove()",
			"Tried to remove an item at position 0 of an empty array. Should have returned false, but returned true.");
		allTestsPass = false;
	}

	arr1.Push("A");
	arr1.Push("B");

	if (arr1.Remove(2) != false)
	{
		ReportFailure("TestRemove()",
			"Tried to remove an item at position 2 for an array with items 0 and 1. Should have returned false, but returned true.");
		allTestsPass = false;
	}

	if (arr1.Remove(-1) != false)
	{
		ReportFailure("TestRemove()",
			"Tried to remove an item at position -1. Should have returned false, but returned true.");
		allTestsPass = false;
	}

	if (arr1.Remove(MAX_SIZE) != false)
	{
		ReportFailure("TestRemove()",
			"Tried to remove an item at position MAX_SIZE. Should have returned false, but returned true.");
		allTestsPass = false;
	}

	// Test 2: Fill array and remove each item
	SmartStaticArray arr2;
	string values[4] = { "K", "C", "M", "O" };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr2.Push(values[i % 4]);
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr2.Remove(0);
	}

	if (arr2.Size() != 0)
	{
		ReportFailure("TestRemove()",
			"Removed all items in an array, using position 0, but result is not an array of size 0.");
		allTestsPass = false;
	}

	// Test 3: Remove an item and compare
	SmartStaticArray arr3, arr4;

	arr3.Push("A");
	arr3.Push("B");
	arr3.Push("C");
	arr3.Push("D");

	arr4.Push("A");
	arr4.Push("C");
	arr4.Push("D");

	arr3.Remove(1);

	if ((arr3 == arr4) == false)
	{
		ReportFailure("TestRemove()",
			"Removed an item at position 1 in an array and the resulting array was wrong.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestRemove()" << endl;
	}

	return allTestsPass;
}


bool Tester_SmartStaticArray::TestGet()
{
	bool allTestsPass = true;

	// Test 1: Invalid index
	SmartStaticArray arr1;

	if (arr1.Get(-1) != "")
	{
		ReportFailure("TestGet()",
			"Created array. Tried to access -1. Result wasn't default value of empty string.");
		allTestsPass = false;
	}
	if (arr1.Get(MAX_SIZE) != "")
	{
		ReportFailure("TestGet()",
			"Created array. Tried to access index MAX_SIZE. Result wasn't the default value of empty string.");
		allTestsPass = false;
	}

	// Test 2: Empty array

	if (arr1.Get(0) != "")
	{
		ReportFailure("TestGet()",
			"Created empty array and tried to access item at position 0. This should be an empty string because this is an empty array, but it was not.");
		allTestsPass = false;
	}

	// Test 3: Fill array and check each item
	SmartStaticArray arr2;
	string values[3] = { "A", "E", "I" };
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr2.Push(values[i % 3]);
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (arr2.Get(i) != values[i % 3])
		{
			ReportFailure("TestGet()",
				"Get failed; expected a value of \"" + values[i % 3] + "\" but instead got values of \"" + arr2.Get(i) + "\"");
			allTestsPass = false;
		}
	}


	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestGet()" << endl;
	}

	return allTestsPass;
}


bool Tester_SmartStaticArray::TestSize()
{
	bool allTestsPass = true;

	// Test 1: Empty array
	SmartStaticArray arr1;
	if (arr1.Size() != 0)
	{
		ReportFailure("TestSize()",
			"Created empty array. Expected Size() to return 0, but it did not.");
		allTestsPass = false;
	}

	// Test 2: Not full, not empty
	SmartStaticArray arr2;
	arr2.Push("A");
	arr2.Push("B");
	arr2.Push("C");
	if (arr2.Size() != 3)
	{
		ReportFailure("TestSize()",
			"Created array with 3 items. Expected Size() to return 3, but it did not.");
		allTestsPass = false;
	}

	// Test 3: Full array
	SmartStaticArray arr3;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr3.Push("asdf");
	}

	if (arr3.Size() != MAX_SIZE)
	{
		ReportFailure("TestSize()",
			"Created full array. Expected Size() to return MAX_SIZE, but it did not.");
		allTestsPass = false;
	}

	// Test 4: Tried to insert too many items
	SmartStaticArray arr4;
	for (int i = 0; i < MAX_SIZE + 2; i++)
	{
		arr4.Push("jkl");
	}

	if (arr4.Size() != MAX_SIZE)
	{
		ReportFailure("TestSize()",
			"Tried to over-fill array. Expected Size() to return MAX_SIZE, but it did not.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestSize()" << endl;
	}

	return allTestsPass;
}

bool Tester_SmartStaticArray::TestIsFull()
{
	bool allTestsPass = true;

	// Test 1: Check empty array
	SmartStaticArray arr1;
	if (arr1.IsFull() == true)
	{
		ReportFailure("TestIsFull()", "Created new array, and it is marked as full, but it's a new array!");
		allTestsPass = false;
	}

	// Test 2: Fill array and check
	SmartStaticArray arr2;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr2.Push("item");
	}
	if (arr2.IsFull() == false)
	{
		ReportFailure("TestIsFull()", "Filled up array, expected it to be marked as full, but it wasn't.");
		allTestsPass = false;
	}

	// Test 3: Fill array, remove one, check
	arr2.Pop();
	if (arr2.IsFull() == true)
	{
		ReportFailure("TestIsFull()", "Popped one off full array, should be marked as not full, but returned full.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestIsFull()" << endl;
	}

	return allTestsPass;
}

bool Tester_SmartStaticArray::TestIsEmpty()
{
	bool allTestsPass = true;

	// Test 1: A new array should be empty
	SmartStaticArray arr1;
	if (arr1.IsEmpty() == false)
	{
		ReportFailure("TestIsEmpty()", "Created new array, expected it to be empty, but it isn't!");
		allTestsPass = false;
	}

	// Test 2: Create an array, push an item, remove an item, see if empty
	SmartStaticArray arr2;
	arr2.Push("test");
	arr2.Pop();
	if (arr2.IsEmpty() == false)
	{
		ReportFailure("TestIsEmpty()", "Created array, pushed and popped item, expected it to be empty, but it isn't!");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestIsEmpty()" << endl;
	}

	return allTestsPass;
}

bool Tester_SmartStaticArray::TestSubscriptOperator()
{
	bool allTestsPass = true;

	// Test 1: Invalid subscripts
	SmartStaticArray arr1;
	if (arr1.Get(MAX_SIZE - 2) != "")
	{
		ReportFailure("TestSubscriptOperator()",
			"Tried to use Get() on empty array, and it didn't return an empty string!");
		allTestsPass = false;
	}
	if (arr1.Get(MAX_SIZE + 2) != "")
	{
		ReportFailure("TestSubscriptOperator()",
			"Tried to use Get() for out-of-bounds index, and it didn't return an empty string!");
		allTestsPass = false;
	}

	// Test 2: Fill array and test all subscripts
	SmartStaticArray arr2;
	string values[5] = { "abcd", "efg", "hijk", "lmnop", "qrs" };
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr2.Push(values[i % 5]);
	}

	// Try to access
	for (int i = 0; i < MAX_SIZE; i++)
	{
		string result = arr2.Get(i);
		if (result != values[i % 5])
		{
			ReportFailure("TestSubscriptOperator()",
				"Used Get() to access an item. Expected \"" + values[i % 5] + "\" but received value \"" + result + "\"!");
			allTestsPass = false;
		}
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestSubscriptOperator()" << endl;
	}

	return allTestsPass;
}

bool Tester_SmartStaticArray::TestAssignmentOperator()
{
	bool allTestsPass = true;

	// Test 1: Set one array to another and validate
	SmartStaticArray arr1, arr2;

	string values[3] = { "a", "b", "c" };

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr1.Push(values[i % 3]);
	}

	// Assign
	arr2 = arr1;

	// Validate
	for (int i = 0; i < MAX_SIZE; i++)
	{
		if (arr1.Get(i) != arr2.Get(i))
		{
			ReportFailure("TestAssignmentOperator()",
				"Used assignment operator to set arr2 to arr1. Validation of elements of both arrays failed.");
			allTestsPass = false;
		}
	}

	// Test 2: Assign one array to an empty array
	SmartStaticArray arr3, arr4;

	arr3 = arr4;

	if (arr3.IsEmpty() == false)
	{
		ReportFailure("TestAssignmentOperator()",
			"Used assignment operator to set arr3 to the empty arr4. arr3 is not being reported as empty, but should be.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestAssignmentOperator()" << endl;
	}

	return allTestsPass;
}

bool Tester_SmartStaticArray::TestEqualityOperator()
{
	bool allTestsPass = true;

	// Test 1: Test on empty arrays
	SmartStaticArray arr1, arr2;
	bool isSame = (arr1 == arr2);
	if (!isSame)
	{
		ReportFailure("TestEqualityOperator()",
			"Tried to compare two empty arrays with == but returned false. Expected true.");
		allTestsPass = false;
	}

	// Test 2: Test on equal arrays
	SmartStaticArray arr3, arr4;

	string values[3] = { "1", "2", "3" };
	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr3.Push(values[i % 3]);
		arr4.Push(values[i % 3]);
	}

	isSame = (arr3 == arr4);
	if (isSame == false)
	{
		ReportFailure("TestEqualityOperator()",
			"Tried to compare two equal arrays with == but returned false. Expected true.");
		allTestsPass = false;
	}

	// Test 3: Test on two arrays that have same elements, up until some point; size is unequal.
	arr3.Pop();
	if (arr3 == arr4)
	{
		ReportFailure("TestEqualityOperator()",
			"Tried to compare two unequal arrays with similar values with == but returned true. Expected false.");
		allTestsPass = false;
	}

	// Test 4: Test on unequal arrays
	string values2[3] = { "1", "2", "5" };
	SmartStaticArray arr5, arr6;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		arr5.Push(values[i % 3]);
		arr6.Push(values2[i % 3]);
	}

	if (arr5 == arr6)
	{
		ReportFailure("TestEqualityOperator()",
			"Tried to compare two unequal arrays with == but returned true. Expected false.");
		allTestsPass = false;
	}

	if (allTestsPass)
	{
		cout << "* ALL TESTS PASSED FOR TestEqualityOperator()" << endl;
	}

	return allTestsPass;
}



void Tester_SmartStaticArray::ReportFailure(const string& test, const string& message)
{
	cout << "TEST FAILED: " << test << "\n"
		<< message << endl << endl;
}