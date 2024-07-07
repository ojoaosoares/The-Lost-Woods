#include "heap.hpp"


template <typename T> 
Heap<T>::Heap(long long maxsize) : size(0)  {
    data = new long long[maxsize];
}

template <typename T> 
Heap<T>::~Heap() {
    delete[] data;
}

template <typename T> 
long long Heap<T>::getFather(long long i){
    return (i-1)/2;
}

template <typename T> 
long long Heap<T>::getLeftChild(long long i){
    return 2 * i + 1;
}

template <typename T> 
long long Heap<T>::getRightChild(long long i){
    return 2 * i + 2;
}

template <typename T> 
bool Heap<T>::empty()
{
    return size == 0;
}

template <typename T> 
void Heap<T>::insert(T x) {

    data[size] = x;

    heapifyDown(size);

    size++;
        
    
}

template <typename T> 
long long Heap<T>::remove()
{
    if (empty())
        throw "Heap is empty";

    long long temp = data[0]; size--;

    if(!empty())
    {
        data[0] = data[size];

        heapifyUp(0);
    }    
    return temp;
}


template <typename T> 
void Heap<T>::heapifyDown(long long pos)
{
    long long current = pos, 
    father = getFather(current);

    while (current > 0 && data[current] < data[father])
    {
        long long temp = data[current];
        data[current] = data[father];
        data[father] = temp;

        current = father;
        father = getFather(current);
    }   
}

template <typename T> 
void Heap<T>::heapifyUp(long long pos)
{
    long long current = pos, smallest_child,
    left = getLeftChild(current),
    right = getRightChild(current);

    if (left >= size)
        return;

    else if (right >= size)
        smallest_child = left;

    else smallest_child = data[left] < data[right] ? left : right;

    while (data[current] > data[smallest_child])
    {
        long long temp = data[current];
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