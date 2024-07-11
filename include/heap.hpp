#ifndef HEAP_HPP
#define HEAP_HPP

#include "tuple.hpp"
#include "utils.hpp"

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
class Heap{

    public:
        Heap(ll maxsize, HashParam hashparam);
        ~Heap();

        void insert(Key key, Value value);
        Tuple<Key, Value>* contains(Key key);
        void update(Key key, Value value);
        Tuple<Key, Value> remove();

        bool empty();

    private:
        ll getFather(ll pos);
        ll getLeftChild(ll pos);
        ll getRightChild(ll pos);

        Comparator comp;
        Hash hash;

        ll size;
        ll maxSize;
        Tuple<Key, Value> *data;
        ll *indexes;

        void heapifyDown(ll pos);
        void heapifyUp(ll pos);
};


#endif