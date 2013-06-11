// Implements a linked list with with hash-table indexing and unique items only.
// Stores only unique items (extendable to non-uniques with worse worst-case runtime complexity)
// Search becomes O(1) for known items, but as opposed to a hash table, 
// it keeps the item ordering
/*
#include <list>
#include <unordered_map>

#define USE_BOOST
#ifdef USE_BOOST
//#include <boost/config.hpp>
//#include <boost/iterator.hpp>
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
	void insert_end( const T& );
	void insert_begin( const T& );

	void remove( const T& ); //O(1)

	//typename list< T >::const_iterator begin() const; //O(1)
	//typename list< T >::const_iterator end() const; //O(1)
	//typename list< T >::iterator begin(); //O(1)
	//typename list< T >::iterator end(); //O(1)

private:
	list< T > ordered_list;
	unordered_map< T, typename list< T >::iterator > indexing;

public:
class h_iterator : public
		boost::iterator_adaptor<
		h_iterator,
		typename list<T>::iterator,
		boost::use_default,
		boost::bidirectional_traversal_tag >
	{
	private:

		typedef boost::iterator_adaptor<
			h_iterator,
			typename list<T>::iterator,
			boost::use_default,
			boost::bidirectional_traversal_tag
		> super_t;

	public:
		h_iterator()
		: super_t(0) {}

		explicit h_iterator( typename list<T>::iterator p)
		: super_t(p) {}

		void increment() {  this->base_reference()++; }
		void decrement() {  this->base_reference()--; }

	};

	h_iterator begin()
	{
		return h_iterator( ordered_list.begin() );
	}

	h_iterator end()
	{
		return h_iterator( ordered_list.end() );
	}

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

template <typename T>
void HashAccelList< T >::insert_begin( const T& val )
{
	list< T >::iterator new_item_it = ordered_list.begin();
	insert( new_item_it, val );
}

template <typename T>
void HashAccelList< T >::insert_end( const T& val )
{
	list< T >::iterator new_item_it = ordered_list.end();
	insert( new_item_it, val );
}
*/


#include <boost/iterator/iterator_adaptor.hpp>
#include <list>

using namespace std;

//forward declaration

template <typename T>
class HashAccelList
{
public:
	//static const int ARR_SZ = 10;
	//T myarr[ARR_SZ];
	list<T> myl;

public:
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

		_iterator( _iterator<T, false>& it ) : super_t( it.base_reference() ) {}

		void increment() { this->base_reference()++; }
		void decrement() { this->base_reference()--; }

		const T& operator*()
		{
			list<T>::const_iterator it = this->base_reference();
			return *(it);
		}

		friend class _iterator<T, true>;
	};

	typedef _iterator<T, false> h_iterator;
	typedef _iterator<T, true> h_const_iterator;

	h_iterator begin()
	{
		return h_iterator( myl.begin() );
	}

	h_iterator end()
	{
		return h_iterator( myl.end() );
	}

	h_const_iterator begin() const
	{
		return h_const_iterator( myl.begin() );
	}

	h_const_iterator end() const
	{
		return h_const_iterator( myl.end() );
	}
};
