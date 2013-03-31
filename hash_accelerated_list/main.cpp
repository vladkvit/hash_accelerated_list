
#include "stdafx.h"
#include <assert.h>

#include "hash_accelerated_list.h"

int _tmain(int argc, _TCHAR* argv[])
{
	const int test_arr[] = { 5, 4, 2, 2, 3, 6, 5 }; //test input
	const int out_arr[] = { 4, 2, 3, 6, 5 }; //wanted output
	HashAccelList< int > mylist;

	for( int i = 0; i < ( sizeof( test_arr ) / sizeof( *test_arr ) ); i++ )
	{
		mylist.insert_end( test_arr[i] );
	}

	mylist.insert_end( 99 );
	mylist.remove( 99 );

	list< int >::const_iterator l_begin = mylist.begin();
	list< int >::const_iterator l_end = mylist.end();

	for( int i = 0; l_begin != l_end; ++l_begin, i++ )
	{
		if( (*l_begin) != out_arr[i] )
			assert( false );

		printf( "%d\n", *l_begin );
	}

	return 0;
}

