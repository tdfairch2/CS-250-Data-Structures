/* Don't modify this file */

#ifndef _TESTER_HPP
#define _TESTER_HPP

#include "LinkedList.hpp"
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

private:
int TestPush2()
{
  InitTest( "TestPush2()", {} );

  StartTest( "Try to push one pair of numbers in, check the values..." );
  int valueX = 2, valueY = 3;
  CoordPairLinkedList cpl;
  cpl.Push2( valueX, valueY );

  int resultX = cpl.Get( 0 );
  int resultY = cpl.Get( 1 );
  int size = cpl.Size();
  if ( resultX != valueX )
  {
    ReportFailure( "Pushed in values "
      + StringUtil::ToString( valueX ) + ", "
      + StringUtil::ToString( valueY ) + " but item #0 is "
      + StringUtil::ToString( resultX ) );

    TestFail();
  }
  else if ( resultY != valueY )
  {
    ReportFailure( "Pushed in values "
      + StringUtil::ToString( valueX ) + ", "
      + StringUtil::ToString( valueY ) + " but item #1 is "
      + StringUtil::ToString( resultY ) );
    TestFail();
  }
  else if ( size != 2 )
  {
    ReportFailure( "Pushed in values "
      + StringUtil::ToString( valueX ) + ", "
      + StringUtil::ToString( valueY ) + ". Size should be 2, but instead it is "
      + StringUtil::ToString( size ) );
    TestFail();
  }
  else
  {
    TestPass();
  }

  StartTest( "Try to push in several pairs of numbers in, check the values..." );

  CoordPairLinkedList cpl2;

  int values[20];
  for ( int i = 0; i < 20; i++ )
  {
    values[i] = rand() % 100 - 50;
  }

  // Push each pair
  cout << endl;
  for ( int i = 0; i <= 19; i += 2 )
  {
    cout << "Push \t" << values[i] << "\t&\t " << values[i+1] << "\t at "
      << i << " and " << i+1;
    cpl2.Push2( values[i], values[i+1] );
    cout << "\t size is now: " << cpl2.Size() << endl;
  }

  cpl2.Display();

  size = cpl2.Size();
  bool testsPass = true;
  if ( size != 20 )
  {
    ReportFailure( "Pushed in 10 pairs. Size should be 20, but instead it is "
      + StringUtil::ToString( size ) );
    testsPass = false;
  }

  // Validate each number
  for ( int i = 0; i <= 19; i++ )
  {
    int a = i;
    int result = cpl2.Get( i );

    if ( result != values[i] )
    {
      ReportFailure( "Expected value "
        + StringUtil::ToString( values[i] ) + " at position "
        + StringUtil::ToString( i ) + " but is "
        + StringUtil::ToString( result ) );
    }
  }

  if ( testsPass )
  {
    TestPass();
  }
  else
  {
    TestFail();
  }

  DisplayScore();
  return TestResult();
}

int TestPop2()
{
  InitTest( "TestPush2()", {} );

  StartTest( "Try to push one pair of numbers in, then pop them out..." );
  CoordPairLinkedList cpl;
  cpl.Push2( 1, 2 );

  int size = cpl.Size();
  bool testsPassed = true;
  if ( size != 2 )
  {
    testsPassed = false;
    ReportFailure( "Pushed in two items. Expected size to be 2, but it is "
      + StringUtil::ToString( size ) );

  }

  cpl.Pop2();
  size = cpl.Size();
  if ( size != 0 )
  {
    testsPassed = false;
    ReportFailure( "Popped two items. Expected size to be 0, but it is "
      + StringUtil::ToString( size ) );
  }

  if ( testsPassed )
  {
    TestPass();
  }
  else
  {
    TestFail();
  }


  StartTest( "Push several items in, then pop them out..." );
  CoordPairLinkedList cpl2;
  cpl2.Push2( 1, 2 );
  cpl2.Push2( 3, 4 );
  cpl2.Push2( 5, 6 );

  size = cpl2.Size();
  testsPassed = true;
  if ( size != 6 )
  {
    testsPassed = false;
    ReportFailure( "Pushed in two items. Expected size to be 6, but it is "
      + StringUtil::ToString( size ) );

  }

  cpl2.Pop2();
  size = cpl2.Size();
  if ( size != 4 )
  {
    testsPassed = false;
    ReportFailure( "Popped two items. Expected size to be 4, but it is "
      + StringUtil::ToString( size ) );
  }

  cpl2.Pop2();
  size = cpl2.Size();
  if ( size != 2 )
  {
    testsPassed = false;
    ReportFailure( "Popped two items. Expected size to be 2, but it is "
      + StringUtil::ToString( size ) );
  }

  cpl2.Pop2();
  size = cpl2.Size();
  if ( size != 0 )
  {
    testsPassed = false;
    ReportFailure( "Popped two items. Expected size to be 0, but it is "
      + StringUtil::ToString( size ) );
  }

  cpl2.Pop2();
  size = cpl2.Size();
  if ( size != 0 )
  {
    testsPassed = false;
    ReportFailure( "Popped two items from empty list. Expected size to be 0, but it is "
      + StringUtil::ToString( size ) );
  }

  if ( testsPassed )
  {
    TestPass();
  }
  else
  {
    TestFail();
  }

  DisplayScore();
  return TestResult();
}

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

};


Tester::Tester()
{
    AddTest( TestListItem( "Push2",          bind( &Tester::TestPush2, this ) ) );
    AddTest( TestListItem( "Pop2",           bind( &Tester::TestPop2, this ) ) );
}

#endif
