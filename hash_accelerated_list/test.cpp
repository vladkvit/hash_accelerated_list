
#include "stdafx.h"
#include <assert.h>

#include "hash_accelerated_list.hpp"

void test1()
{
	const int test_arr[] = { 5, 4, 2, 2, 3, 6, 5 }; //test input
	const int out_arr[] = { 4, 2, 3, 6, 5 }; //wanted output
	HashAccelList< int > mylist;

	for( int i = 0; i < ( sizeof( test_arr ) / sizeof( *test_arr ) ); i++ )
	{
		mylist.insert_end( test_arr[i] );
	}

	mylist.insert_begin( 99 );
	mylist.remove( 99 );

	list< int >::const_iterator l_begin = mylist.begin();
	list< int >::const_iterator l_end = mylist.end();

	for( int i = 0; l_begin != l_end; ++l_begin, i++ )
	{
		//assert( false ) triggers the assert
		assert( (*l_begin) == out_arr[i] );
	}
}

void test2()
{
	const int out_arr[] = { 2, -1, 4 }; //wanted output
	
	HashAccelList< int > mylist;
	mylist.insert_end( 4 );
	mylist.insert_begin( 2 );
	list< int >::iterator it = mylist.end();
	it--;
	mylist.insert( it, -1 );

	list< int >::const_iterator l_begin = mylist.begin();
	list< int >::const_iterator l_end = mylist.end();
	for( int i = 0; l_begin != l_end; ++l_begin, i++ )
	{
		//assert( false ) triggers the assert
		assert( (*l_begin) == out_arr[i] );
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();

	return 0;
}

