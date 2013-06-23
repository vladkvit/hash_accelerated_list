#include "hash_accelerated_list.hpp"

#include <unordered_set>

using namespace std;

template <typename T>
class MultiHashAccelList
{
public:
	MultiHashAccelList() {}

private:
	list< T > ordered_list;

	//HashAccelList< typename list< T >::iterator > test;
	//unordered_set< typename list< T >::iterator > test;
	//unordered_map< T, typename HashAccelList< typename list< T >::iterator > > indexing;
};