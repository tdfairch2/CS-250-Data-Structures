#ifndef _TESTER_SMART_STATIC_ARRAY_HPP
#define _TESTER_SMART_STATIC_ARRAY_HPP

#include "SmartStaticArray.hpp"

#include <string>
#include <iostream>
using namespace std;

class Tester_SmartStaticArray
{
	public:
	static void Start();

	private:
	static bool TestPush();
	static bool TestInsert();
	static bool TestExtend();
	static bool TestPop();
	static bool TestRemove();
	static bool TestGet();
	static bool TestSize();
	static bool TestIsFull();
	static bool TestIsEmpty();
	static bool TestSubscriptOperator();
	static bool TestAssignmentOperator();
	static bool TestEqualityOperator();

	private:
	static void ReportFailure( const string& test, const string& message );
};

#endif
