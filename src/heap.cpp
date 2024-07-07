#include "heap.hpp"


template <typename T, class Comparator>
Heap<T, Comparator>::Heap(long long maxsize) : size(0)  {
    data = new long long[maxsize];
}

template <typename T, class Comparator>
Heap<T, Comparator>::~Heap() {
    delete[] data;
}

template <typename T, class Comparator>
long long Heap<T, Comparator>::getFather(long long i){
    return (i-1)/2;
}

template <typename T, class Comparator>
long long Heap<T, Comparator>::getLeftChild(long long i){
    return 2 * i + 1;
}

template <typename T, class Comparator>
long long Heap<T, Comparator>::getRightChild(long long i){
    return 2 * i + 2;
}

template <typename T, class Comparator>
bool Heap<T, Comparator>::empty()
{
    return size == 0;
}

template <typename T, class Comparator>
void Heap<T, Comparator>::insert(T x) {

    data[size] = x;

    heapifyDown(size);

    size++;
}

template <typename T, class Comparator>
T Heap<T, Comparator>::remove()
{
    if (empty())
        throw "Heap is empty";

    T temp = data[0]; size--;

    if(!empty())
    {
        data[0] = data[size];

        heapifyUp(0);
    }    
    return temp;
}


template <typename T, class Comparator>
void Heap<T, Comparator>::heapifyDown(long long pos)
{
    long long current = pos, 
    father = getFather(current);

    while (current > 0 && comp(data[current], data[father]))
    {
        T temp = data[current];
        data[current] = data[father];
        data[father] = temp;

        current = father;
        father = getFather(current);
    }   
}

template <typename T, class Comparator>
void Heap<T, Comparator>::heapifyUp(long long pos)
{
    long long current = pos, smallest_child,
    left = getLeftChild(current),
    right = getRightChild(current);

    if (left >= size)
        return;

    else if (right >= size)
        smallest_child = left;

    else smallest_child = data[left] < data[right] ? left : right;

    while (comp(data[smallest_child], data[current]))
    {
        T temp = data[current];
        data[current] = data[smallest_child];
        data[smallest_child] = temp;

        current = smallest_child;
        left = getLeftChild(current);
        right = getRightChild(current);

        if (left >= size)
            return;

        else if (right >= size)
            smallest_child = left;

        else smallest_child = data[left] < data[right] ? left : right;
    }

}