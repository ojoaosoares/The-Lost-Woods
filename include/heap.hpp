#ifndef HEAP_HPP
#define HEAP_HPP

#include "tuple.hpp"

typedef long long ll;

template <typename Key, typename Value, class Comparator, class Hash>
class Heap{

    public:
        Heap(ll maxsize, Comparator comp, Hash hash);
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

        ll size;
        ll maxSize;

        Tuple<Key, Value> *data;
        ll *indexes;

        Comparator comp;
        Hash hash;

        void heapifyDown(ll pos);
        void heapifyUp(ll pos);
};

class Hash_Custom {

    private:
        ll vert, portals;

    public:
        Hash_Custom(ll vertice, ll portals);
        ll operator() (const Tuple<ll, ll>& key) const;

};

class Comp_Dijkstra {
    public:
        bool operator() (const double& v1, const double& v2) const;

};

class Comp_A_Star {
    public:
        bool operator() (const Tuple<double, double>& v1, const Tuple<double, double>& v2) const;
};

#endif