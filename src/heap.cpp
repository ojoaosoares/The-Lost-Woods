#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
Heap<Key, Value, Comparator, Hash, HashParam>::Heap(ll maxsize, HashParam hashparam) : hash(hashparam), size(0), maxSize(maxsize), data(new Tuple<Key, Value>[maxsize]), indexes(new ll[maxsize]) {
    for (ll i = 0; i < maxsize; i++) indexes[i] = -1;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
Heap<Key, Value, Comparator, Hash, HashParam>::~Heap() {
    delete[] data; delete[] indexes;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
ll Heap<Key, Value, Comparator, Hash, HashParam>::getFather(ll i){
    return (i-1)/2;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
ll Heap<Key, Value, Comparator, Hash, HashParam>::getLeftChild(ll i){
    return 2 * i + 1;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
ll Heap<Key, Value, Comparator, Hash, HashParam>::getRightChild(ll i){
    return 2 * i + 2;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
bool Heap<Key, Value, Comparator, Hash, HashParam>::empty()
{
    return size == 0;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
Tuple<Key, Value>* Heap<Key, Value, Comparator, Hash, HashParam>::contains(Key key)
{
    ll index = indexes[hash(key)];

    if (index == -1) return nullptr;

    return &data[index];
}


template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
void Heap<Key, Value, Comparator, Hash, HashParam>::insert(Key key, Value value) {

    if (size == maxSize)
        throw "Heap is full";

    data[size].first = key;
    data[size].second = value;

    indexes[hash(key)] = size;

    heapifyDown(size);

    size++;
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
void Heap<Key, Value, Comparator, Hash, HashParam>::update(Key key, Value value) {

    Tuple<Key, Value>* item = contains(key);
    if (item == nullptr)
        throw "Index doesn't exist";

    item->second = value;
    if (comp(value, item->second))    
        heapifyDown(indexes[hash(key)]);
    

    else
        heapifyUp(indexes[hash(key)]);
    
    
    
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
Tuple<Key, Value> Heap<Key, Value, Comparator, Hash, HashParam>::remove()
{
    if (empty())
        throw "Heap is empty";

    Tuple<Key, Value> temp = data[0];
    indexes[hash(data[0].first)] = -1; size--;

    if(!empty())
    {
        data[0] = data[size];
        indexes[hash(data[0].first)] = 0;

        heapifyUp(0);
    }

    return temp;
}


template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
void Heap<Key, Value, Comparator, Hash, HashParam>::heapifyDown(ll pos)
{
    ll current = pos, 
    father = getFather(current);

    while (current > 0 && comp(data[current].second, data[father].second))
    {
        Tuple<Key, Value> temp = data[current];
        data[current] = data[father];
        data[father] = temp;

        ll temp_index = indexes[hash(data[current].first)];
        indexes[hash(data[current].first)] = indexes[hash(data[father].first)];
        indexes[hash(data[father].first)] = temp_index;

        current = father;
        father = getFather(current);
    }   
}

template <typename Key, typename Value, class Comparator, class Hash, typename HashParam>
void Heap<Key, Value, Comparator, Hash, HashParam>::heapifyUp(ll pos)
{
    ll current = pos, smallest_child,
    left = getLeftChild(current),
    right = getRightChild(current);

    if (left >= size)
        return;

    else if (right >= size)
        smallest_child = left;

    else smallest_child = comp(data[left].second, data[right].second) ? left : right;

    while (comp(data[smallest_child].second, data[current].second))
    {
        Tuple<Key, Value> temp = data[current];
        data[current] = data[smallest_child];
        data[smallest_child] = temp;

        ll temp_index = indexes[hash(data[current].first)];
        indexes[hash(data[current].first)] = indexes[hash(data[smallest_child].first)];
        indexes[hash(data[smallest_child].first)] = temp_index;

        current = smallest_child;
        left = getLeftChild(current);
        right = getRightChild(current);

        if (left >= size)
            return;

        else if (right >= size)
            smallest_child = left;

        else smallest_child = comp(data[left].second, data[right].second) ? left : right;
    }

}


template class Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods, Tuple<ll, ll>>;