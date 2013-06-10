
#include "stdafx.h"
#include <assert.h>
#include <algorithm>

#include <set>

#include "hash_accelerated_list.hpp"

void test1()
{
	/*const int test_arr[] = { 5, 4, 2, 2, 3, 6, 5 }; //test input
	const int out_arr[] = { 4, 2, 3, 6, 5 }; //wanted output
	HashAccelList< int > mylist;*/
/*
	for( int i = 0; i < ( sizeof( test_arr ) / sizeof( *test_arr ) ); i++ )
	{
		mylist.insert_end( test_arr[i] );
	}

	mylist.insert_begin( 99 );
	mylist.remove( 99 );*/

	/*list< int >::const_iterator l_begin = mylist.begin();
	list< int >::const_iterator l_end = mylist.end();

	for( int i = 0; l_begin != l_end; ++l_begin, i++ )
	{
		//assert( false ) triggers the assert
		assert( (*l_begin) == out_arr[i] );
	}*/
}

void test2()
{
	/*const int out_arr[] = { 2, -1, 4 }; //wanted output
	
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
	}*/
}

void test3()
{
	HashAccelList< int > mylist;
	for( int i = 0; i < 10; i++ )
	{
		mylist.myl.push_back( i + 1000 );
	}
	
	printf( "%d\n", mylist.myl.front() );
	HashAccelList< int >::h_iterator my_iterator( mylist.myl.begin() );
	printf( "%d\n", *my_iterator );
	printf("\n");
	
	printf( "%d\n", mylist.myl.front() );
	my_iterator = mylist.begin();
	++my_iterator;
	printf( "%d\n", *my_iterator );
	printf("\n");

	printf("%d\n", mylist.myl.back() );
	my_iterator = mylist.end();
	--my_iterator; //end is not the last element
	printf( "%d\n", *my_iterator );
	--my_iterator;
	printf( "%d\n", *my_iterator );
	printf("\n");



	for( my_iterator = mylist.begin(); my_iterator != mylist.end(); ++my_iterator )
	{
		printf( "%d\n", *my_iterator );
	}
	printf("\n");

	next_permutation( mylist.begin(), mylist.end() );
	next_permutation( mylist.begin(), mylist.end() );
	next_permutation( mylist.begin(), mylist.end() );
	for( my_iterator = mylist.begin(); my_iterator != mylist.end(); ++my_iterator )
	{
		printf( "%d\n", *my_iterator );
	}
	printf("\n");

}

void test4()
{
	set<int> myset;
	myset.insert( 5 );
	myset.insert( 1 );
	myset.insert( 3 );

	set<int>::iterator it = myset.begin();


}

void test5()
{
	HashAccelList< int > mylist;
	for( int i = 0; i < 10; i++ )
	{
		mylist.myl.push_back( i + 1000 );
	}

	HashAccelList< int >::h_const_iterator my_iterator2 = mylist.cbegin();

}

int _tmain(int argc, _TCHAR* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}

