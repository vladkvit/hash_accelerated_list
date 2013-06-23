
#include "stdafx.h"
#include <assert.h>
#include <algorithm>

#include <set>

#include "hash_accelerated_list.hpp"

void test1()
{
	const int test_arr[] = { 5, 4, 2, 2, 3, 6, 5 }; //test input
	const int out_arr[] = { 4, 2, 3, 6, 5 }; //wanted output
	HashAccelList< int > mylist;

	for( int i = 0; i < ( sizeof( test_arr ) / sizeof( *test_arr ) ); i++ )
	{
		mylist.push_back( test_arr[i] );
	}

	mylist.push_front( 99 );
	mylist.remove( 99 );

	HashAccelList< int >::h_iterator l_begin = mylist.begin();
	HashAccelList< int >::h_iterator l_end = mylist.end();

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
	mylist.push_front( 2 );
	mylist.push_back( 4 );
	HashAccelList< int >::h_iterator it = mylist.end();
	it--;
	mylist.insert( it, -1 );

	HashAccelList< int >::h_const_iterator l_begin = mylist.begin();
	HashAccelList< int >::h_const_iterator l_end = mylist.end();
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

	printf("Tests passed\n");

	return 0;
}

