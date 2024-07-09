#include "heap.hpp"

template <typename Key, typename Value, class Comparator, class Hash>
Heap<Key, Value, Comparator, Hash>::Heap(long long maxsize) : size(0), maxSize(maxsize), data(new Tuple<Key, Value>[maxsize]), indexes(new long long[maxsize]) {
    for (long long i = 0; i < maxsize; i++) indexes[i] = -1;
}

template <typename Key, typename Value, class Comparator, class Hash>
Heap<Key, Value, Comparator, Hash>::~Heap() {
    delete[] data; delete[] indexes;
}

template <typename Key, typename Value, class Comparator, class Hash>
long long Heap<Key, Value, Comparator, Hash>::getFather(long long i){
    return (i-1)/2;
}

template <typename Key, typename Value, class Comparator, class Hash>
long long Heap<Key, Value, Comparator, Hash>::getLeftChild(long long i){
    return 2 * i + 1;
}

template <typename Key, typename Value, class Comparator, class Hash>
long long Heap<Key, Value, Comparator, Hash>::getRightChild(long long i){
    return 2 * i + 2;
}

template <typename Key, typename Value, class Comparator, class Hash>
bool Heap<Key, Value, Comparator, Hash>::empty()
{
    return size == 0;
}

template <typename Key, typename Value, class Comparator, class Hash>
long long Heap<Key, Value, Comparator, Hash>::contains(Key key)
{
    return indexes[hash(key, maxSize)];
}


template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::insert(Key key, Value value) {

    if (size == maxSize)
        throw "Heap is full";

    data[size].first = key;
    data[size].second = value;

    indexes[hash(key, maxSize)] = size;

    heapifyDown(size);

    size++;
}

template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::update(Key key, Value value) {

    long long index = contains(key);
    if (contains == -1)
        throw "Index doesn't exist";

    if (comp(value, data[index]))
    {
        data[index].second = value;
        heapifyDown(index);
    }

    else
    {
        data[index].second = value;
        heapifyUp(index);
    }
    
    
}

template <typename Key, typename Value, class Comparator, class Hash>
Tuple<Key, Value> Heap<Key, Value, Comparator, Hash>::remove()
{
    if (empty())
        throw "Heap is empty";

    Tuple<Key, Value> temp = data[0];
    indexes[hash(data[0].first, maxSize)] = -1; size--;

    if(!empty())
    {
        data[0] = data[size];
        indexes[hash(data[0].first, maxSize)] = 0;

        heapifyUp(0);
    }

    return temp;
}


template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::heapifyDown(long long pos)
{
    long long current = pos, 
    father = getFather(current);

    while (current > 0 && comp(data[current], data[father]))
    {
        T temp = data[current];
        data[current] = data[father];
        data[father] = temp;

        long long temp_index = indexes[data[current].first];
        indexes[data[current].first] = indexes[data[father].first];
        indexes[data[father].first] = temp_index;

        current = father;
        father = getFather(current);
    }   
}

template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::heapifyUp(long long pos)
{
    long long current = pos, smallest_child,
    left = getLeftChild(current),
    right = getRightChild(current);

    if (left >= size)
        return;

    else if (right >= size)
        smallest_child = left;

    else smallest_child = comp(data[left], data[right]) ? left : right;

    while (comp(data[smallest_child], data[current]))
    {
        T temp = data[current];
        data[current] = data[smallest_child];
        data[smallest_child] = temp;

        long long temp_index = indexes[data[current].first];
        indexes[data[current].first] = indexes[data[smallest_child].first];
        indexes[data[smallest_child].first] = temp_index;

        current = smallest_child;
        left = getLeftChild(current);
        right = getRightChild(current);

        if (left >= size)
            return;

        else if (right >= size)
            smallest_child = left;

        else smallest_child = comp(data[left], data[right]) ? left : right;
    }

}


template class Heap<long long, std::less<long long>>;