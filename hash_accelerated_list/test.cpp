
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
	const int out_arr[] = { 2, -1, 4 }; //wanted output
	
	HashAccelList< int > mylist;
	mylist.insert_end( 4 );
	mylist.insert_begin( 2 );
	HashAccelList< int >::h_iterator it = mylist.end();
	it--;
	//mylist.insert( it, -1 );

	HashAccelList< int >::h_const_iterator l_begin = mylist.begin();
	HashAccelList< int >::h_const_iterator l_end = mylist.end();
	for( int i = 0; l_begin != l_end; ++l_begin, i++ )
	{
		//assert( false ) triggers the assert
		assert( (*l_begin) == out_arr[i] );
	}
}

void test3()
{
	/*HashAccelList< int > mylist;
	for( int i = 0; i < 10; i++ )
	{
		mylist.myl.push_back( i + 1000 );
	}
	
	printf( "1000, %d\n", mylist.myl.front() );
	HashAccelList<int>::h_iterator my_iterator = mylist.begin();
	printf( "1000, %d\n", *my_iterator );
	++my_iterator;
	printf( "1001, %d\n", *my_iterator );
	--my_iterator;
	printf( "1000, %d\n", *my_iterator );
	printf("\n");
	
	printf("1009, %d\n", mylist.myl.back() );
	my_iterator = mylist.end();
	--my_iterator; //end is not the last element
	printf( "1009, %d\n", *my_iterator );
	--my_iterator;
	printf( "1008, %d\n", *my_iterator );
	printf("\n");
	
	int i = 1000;
	for( my_iterator = mylist.begin(); my_iterator != mylist.end(); ++my_iterator )
	{
		printf( "%d, %d\n", i, *my_iterator );
		i++;
	}
	printf("\n");

	
	printf( "1000, %d\n", mylist.myl.front() );
	HashAccelList<int>::h_const_iterator cit = mylist.begin();
	printf( "1000, %d\n", *cit );
	++cit;
	printf( "1001, %d\n", *cit );
	--cit;
	printf( "1000, %d\n", *cit );
	printf("\n");

	const HashAccelList< int > mylist2;
	for( int i = 0; i < 10; i++ )
	{
		mylist.myl.push_back( i + 1000 );
	}
	printf( "1000, %d\n", mylist.myl.front() );
	HashAccelList<int>::h_const_iterator cit2 = mylist2.begin();
	printf( "1000, %d\n", *cit );
	++cit;
	printf( "1001, %d\n", *cit );
	--cit;
	printf( "1000, %d\n", *cit );
	printf("\n");

	//The below should not compile if uncommented
	//HashAccelList<int>::h_const_iterator cit2 = mylist2.begin();*/
}

void test4()
{
	set<int> myset;
	myset.insert( 5 );
	myset.insert( 1 );
	myset.insert( 3 );

	//next_permutation( myset.begin(), myset.end() );

	set<int>::iterator it = myset.begin();
	set<int>::const_iterator it2 = myset.begin();

}

void test5()
{
	/*HashAccelList< int > mylist;
	for( int i = 0; i < 10; i++ )
	{
		mylist.myl.push_back( i + 1000 );
	}

	HashAccelList< int >::h_const_iterator my_iterator2 = mylist.begin();*/

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

