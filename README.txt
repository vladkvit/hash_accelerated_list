This project implements a linked list with hash-table indexing and unique items only.
Stores only unique items (see below for non-unique items and how to implement that)
This data structure keeps the O(1) times of a hash table, but keeps the item ordering.

In Java, this data structure is called a LinkedHashMap.

Since I only wrote this to familiarize myself with C++'s STL & iterators, don't expect the API to be nice or complete.

This data structure is extendable to non-unique item storage.
The naive non-unique implementation (a linked-list of pointers for each cell in the hash table) leads to a worst-case O(N) remove( iterator ) performance (when N identical items are inserted). The solution to this would be to make an unordered_map of unordered_sets that store the iterators. This would then guarantee O(1) remove(iterator) performance. However, the find( value ) traversal would not be in order of insertion. In order to make it in order of insertion, replace the unordered_sets with LinkedHashMaps.

If using boost: edit the boost paths in hash_accelerated_list/hash_accelerated_list/boost_property.props.
If not using boost: remove the #define USE_BOOST from hash_accelerated_list/hash_accelerated_list/hash_accelerated_list.hpp.

TODO:
More complete API
Finish MultiHashAccelList
More tests