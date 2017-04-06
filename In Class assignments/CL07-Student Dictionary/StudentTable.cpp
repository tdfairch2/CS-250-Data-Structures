#include "StudentTable.hpp"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* DONE */ StudentTable::StudentTable()
{
    m_collisionMethod = LINEAR; // default
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        // Initialize students
        m_students[i].key = -1;
        m_students[i].value = "";
    }
}

/* DONE */ void StudentTable::SetCollisionMethod( CollisionMethod cm )
{
    cout << "Collision method: " << cm << endl << endl;
    m_collisionMethod = cm;
}

/* Insert
Take in the studentId (key) and name (value), and
use your hash function to figure out an index
for this new value.
Then, set the values of the Student object in the array.
*/
void StudentTable::Insert( int studentId, const string& name )
{
    // Generate index from the studentId
    // Insert into the m_students array
}

/* DONE */ void StudentTable::Output( const string& filename )
{
    cout << "Output table to: " << filename << endl << endl;

    ofstream output( filename );
    for ( int i = 0; i < TABLE_SIZE; i++ )
    {
        output << i << ".";
        if ( i < 10 )
        {
            output << "   ";
        }
        else if ( i < 100 )
        {
            output << "  ";
        }
        else
        {
            output << " ";
        }

        if ( m_students[i].key != -1 )
        {
            output << "Student ID: " << m_students[i].key << " \t Student Name: " << m_students[i].value;
        }
        output << endl;
    }
    output.close();
}

/* HashFunction
Take in the key and generate an index.
This function should handle collisions, and
the returned index should be the index of an
available "slot" in the array.

Use an if statement to decide which collision
method to use.
*/

	cout << "Enter method:  LINEAR or QUADRATIC" << endl;

	cin >> string m_collisionMethod >> endl;

		if (m_collisionMethod == LINEAR)
		{
			//int StudentTable::HashFunction( int key )
			//{
			//    return -1; // Distinctive return
			//}

			/* Linear probing
				You can use my function prototype or write your own.
			*/
			int StudentTable::LinearProbe(int key)
			{
				return -1; // Distinctive return
			}
		}

		/* Quadratic probing
			You can use my function prototype or write your own.
		*/

		//if (m_collisionMethod == QUADRATIC)
		//{
		//	int StudentTable::QuadraticProbe(int key, int& addValue)
		//	{
		//		return -1; // Distinctive return
		//	}

			/* Double hashing  -- attempted later
				You can use my function prototype or write your own.
			*/
			//int StudentTable::HashFunction2( int key )
			//{
			//	return -1; // Distinctive return
			//}
		//}