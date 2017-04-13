/* Don't modify this file */

#ifndef _TESTER_HPP
#define _TESTER_HPP

#include "StudentCode.hpp"
#include "cuTEST/StringUtil.hpp"
#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"

#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int ARBITRARY_SIZE = 50;

class Tester : public TesterBase
{
    public:
    Tester();

    int TestQueuePop();

    private:

    vector<string> GetTestItems( int size )
    {
        vector<string> arr;
        for ( int i = 0; i < size; i++ )
        {
            string blah = "";

            for ( int j = 1; j < ( rand() % 10 + 3 ); j++ )
            {
                int ascii = ( rand() % 25 ) + 65;
                blah += char( ascii );
            }

            arr.push_back( blah );
        }

        return arr;
    }

    void QueuePush( Queue& q, int value );

};


Tester::Tester()
{
    AddTest( TestListItem( "TestQueuePop",          bind( &Tester::TestQueuePop, this ) ) );
//    AddTest( TestListItem( "Pop2",           bind( &Tester::TestPop2, this ) ) );
}

int Tester::TestQueuePop()
{
    InitTest( "TestQueuePop", {} );
    // Test 1: Pop nothing
    StartTest( "Test POP with empty queue." );
    Queue q1;
    bool result = q1.Pop();
    if ( result == true )
    {
        TestFail();
        ReportFailure( "TestQueuePop 1 a",
            "POP on empty array didn't return FALSE." );
    }
    else if ( q1.m_itemCount != 0 )
    {
        TestFail();
        ReportFailure( "TestQueuePop 1 b",
            "POP on empty array... the item count isn't correct!",
            "0", StringUtil::ToString( q1.m_itemCount ) );
    }
    else
    {
        TestPass();
    }

    // Test 2: Pop last item
    StartTest( "Test POP of last item!" );
    Queue q2;
    QueuePush( q2, 5 );
    result = q2.Pop();
    if ( result == false )
    {
        TestFail();
        ReportFailure( "TestQueuePop 2 a",
            "POP on last item in queue... result was false, but should be true." );
    }
    else if ( q2.m_itemCount != 0 )
    {
        TestFail();
        ReportFailure( "TestQueuePop 2 b",
            "POP on last item in queue... but the item count isn't 0!",
            "0", StringUtil::ToString( q2.m_itemCount ) );
    }
    else if ( q2.m_ptrFirst != nullptr )
    {
        TestFail();
        ReportFailure( "TestQueuePop 2 c",
            "POP on last item in queue... m_ptrFirst isn't null!" );
    }
    else if ( q2.m_ptrLast != nullptr )
    {
        TestFail();
        ReportFailure( "TestQueuePop 2 d",
            "POP on last item in queue... m_ptrLast isn't null!" );
    }
    else
    {
        TestPass();
    }

    // Test 3: Pop several items from queue with multiple items
    StartTest( "Test POP on two items!" );
    Queue q3;
    QueuePush( q3, 5 );
    QueuePush( q3, 6 );
    QueuePush( q3, 7 );
    QueuePush( q3, 8 );
    Queue q3b;
    QueuePush( q3b, 5 );
    QueuePush( q3b, 6 );
    QueuePush( q3b, 7 );
    QueuePush( q3b, 8 );

    // Make sure the correct items are popped.
    result = q3.Pop();
    result = q3.Pop();

    bool fail = true;
    if ( result == false )
    {
        TestFail();
        ReportFailure( "TestQueuePop 3 a",
            "POP on last item in queue... result was false, but should be true." );
    }
    else if ( q3.m_itemCount != 2 )
    {
        TestFail();
        ReportFailure( "TestQueuePop 3 b",
            "Popped two items from queue with 4 items; item count is not 2 now.",
            "2", StringUtil::ToString( q3.m_itemCount ) );
    }
    else if ( q3.m_ptrFirst->data != 7 )
    {
        TestFail();
        ReportFailure( "TestQueuePop 3 c",
            "Popped two items from queue with 4 items. First item is not correct.",
            "7", StringUtil::ToString( q3.m_ptrFirst->data ) );
    }
    else if ( q3.m_ptrLast->data != 8 )
    {
        TestFail();
        ReportFailure( "TestQueuePop 3 d",
            "Popped two items from queue with 4 items. Last item is not correct.",
            "8", StringUtil::ToString( q3.m_ptrLast->data ) );
    }
    else if ( q3.m_ptrFirst->ptrPrev != nullptr )
    {
        TestFail();
        ReportFailure( "TestQueuePop 3 e",
            "ptrFirst's previous pointer isn't nullptr." );
    }
    else
    {
        fail = false;
        TestPass();
    }
    if ( fail )
    {
        TesterMessage( "Queue before pop:" );
        q3b.Display();

        TesterMessage( "Queue after pop:" );
        q3.Display();
    }

    DisplayScore();
    return TestResult();
}

void Tester::QueuePush( Queue& q, int value )
{
    Node* newNode = new Node;
    newNode->data = value;

    if ( q.m_ptrFirst == nullptr )
    {
        q.m_ptrFirst = newNode;
        q.m_ptrLast = newNode;
    }
    else
    {
        q.m_ptrLast->ptrNext = newNode;
        newNode->ptrPrev = q.m_ptrLast;
        q.m_ptrLast = newNode;
    }

    q.m_itemCount++;
}

#endif
