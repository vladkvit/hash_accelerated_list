// Implements a linked list with with hash-table indexing and unique items only.
// Stores only unique items (extendable to non-uniques with worse worst-case runtime complexity)
// Search becomes O(1) for known items, but as opposed to a hash table, 
// it keeps the item ordering

#include <list>
#include <unordered_map>

#define USE_BOOST
#ifdef USE_BOOST
#include <boost/iterator/iterator_adaptor.hpp>
#endif

using namespace std;

template <typename T>
class HashAccelList
{
public:
	HashAccelList() {}

	//the inserts are O(1), they also remove the previous instance of the parameter
	void HashAccelList< T >::insert( typename list< T >::iterator, const T& );
	void push_back( const T& );
	void push_front( const T& );

	void remove( const T& ); //O(1)

private:
	list< T > ordered_list;
	unordered_map< T, typename list< T >::iterator > indexing;

public:
#ifdef USE_BOOST
	template <typename T, bool c> //c determines if it is a const_iterator or not
	class _iterator : public
		boost::iterator_adaptor<
		_iterator<T, c>,
		typename std::conditional< c, typename list<T>::const_iterator, typename list<T>::iterator >::type,
		boost::use_default,
		boost::bidirectional_traversal_tag >
	{
	private:
		typedef boost::iterator_adaptor<
			_iterator<T, c>,
			typename std::conditional< c, typename list<T>::const_iterator, typename list<T>::iterator >::type,
			boost::use_default,
			boost::bidirectional_traversal_tag
		> super_t;

	public:
		explicit _iterator( typename std::conditional<c, typename list<T>::const_iterator, typename list<T>::iterator>::type p )
		: super_t(p) {}

		//copy constructor so we can auto-convert iterators into const_iterators
		//needed since begin() from non-const "this" only returns a non-const iterator
		_iterator( _iterator<T, false>& it ) : super_t( it.base_reference() ) {}

		void increment() { this->base_reference()++; }
		void decrement() { this->base_reference()--; }

		const T& operator*() const
		{
			list<T>::const_iterator it = this->base_reference();
			return *(it);
		}

		friend class _iterator<T, true>;
		friend class HashAccelList<T>;
	};

	typedef _iterator<T, false> h_iterator;
	typedef _iterator<T, true> h_const_iterator;

	void insert( typename HashAccelList< T >::h_iterator it, const T& val );

	h_iterator begin()
	{
		return h_iterator( ordered_list.begin() );
	}

	h_iterator end()
	{
		return h_iterator( ordered_list.end() );
	}

	const h_const_iterator begin() const
	{
		return h_const_iterator( ordered_list.begin() );
	}

	const h_const_iterator end() const
	{
		return h_const_iterator( ordered_list.end() );
	}
#endif
};

//Since I'm using templates, the implementation has to go into the header

template <typename T>
void HashAccelList< T >::remove( const T& val )
{
	unordered_map< T, typename list< T >::iterator >::iterator hash_item = indexing.find( val );
	if( hash_item != indexing.end() )
	{
		ordered_list.erase( hash_item->second );
		indexing.erase( hash_item );
	}
}

template <typename T>
void HashAccelList< T >::insert( typename list< T >::iterator new_item_it, const T& val )
{
	//get the old value
	unordered_map< T, typename list< T >::iterator >::iterator hash_item = indexing.find( val );
	
	new_item_it = ordered_list.insert( new_item_it, val );
	if( hash_item != indexing.end() )
	{
		ordered_list.erase( hash_item->second );
		hash_item->second = new_item_it;
	}
	else
	{
		indexing.insert( make_pair( val, new_item_it ) );
	}
}

#ifdef USE_BOOST
template <typename T>
void HashAccelList< T >::insert( typename HashAccelList< T >::h_iterator position, const T& val )
{
	list< T >::iterator pos = position.base_reference();
	insert( pos, val );
}
#endif

template <typename T>
void HashAccelList< T >::push_front( const T& val )
{
	list< T >::iterator new_item_it = ordered_list.begin();
	insert( new_item_it, val );
}

template <typename T>
void HashAccelList< T >::push_back( const T& val )
{
	list< T >::iterator new_item_it = ordered_list.end();
	insert( new_item_it, val );
}
