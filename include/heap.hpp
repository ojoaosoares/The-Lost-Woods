#ifndef HEAP_HPP
#define HEAP_HPP

#include <functional>

template <typename T, class Comparator = std::less<T>>
class Heap{

    public:
        Heap(long long maxsize);
        ~Heap();


        void insert(T x);
        T remove();

        bool empty();

    private:
        long long getFather(long long pos);
        long long getLeftChild(long long pos);
        long long getRightChild(long long pos);

        Comparator comp;

        long long size;
        T* data;

        void heapifyDown(long long pos);
        void heapifyUp(long long pos);
};


#endif