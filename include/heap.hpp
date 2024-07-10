#ifndef HEAP_HPP
#define HEAP_HPP

#include "tuple.hpp"

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
class Heap{

    public:
        Heap(long long maxsize, HashParam hashparam);
        ~Heap();

        void insert(Key key, Value value);
        Tuple<Key, Value>* contains(Key key);
        void update(Key key, Value value);
        Tuple<Key, Value> remove();

        bool empty();

    private:
        long long getFather(long long pos);
        long long getLeftChild(long long pos);
        long long getRightChild(long long pos);

        Comparator comp;
        Hash hash;

        long long size;
        long long maxSize;
        Tuple<Key, Value> *data;
        long long *indexes;

        void heapifyDown(long long pos);
        void heapifyUp(long long pos);
};


#endif