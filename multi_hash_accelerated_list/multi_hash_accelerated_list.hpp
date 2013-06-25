#include "hash_accelerated_list.hpp"

#include <unordered_set>

using namespace std;

struct list_iterator_hash {
    size_t operator()(const list<int>::iterator &i) const {
        return hash<int*>()(&*i);
    }
};

template <typename T>
class MultiHashAccelList
{
public:
	MultiHashAccelList() {}

private:
	/*list< T > ordered_list;

	class testclass
	{
		int i;
		char j;
	};

	list< T >::iterator x;
	HashAccelList< typename list< T >::iterator > test;
	unordered_set< testclass > test;*/
	unordered_map< T, typename list< T >::iterator,  list_iterator_hash > indexing;

	//unordered_set< typename list< int >::iterator > myhashset;
};