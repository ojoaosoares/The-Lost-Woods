#ifndef HEAP_HPP
#define HEAP_HPP

template <typename T>
class Heap{

    public:
        Heap(long long maxsize);
        ~Heap();

        void insert(T x);
        long long remove();

        
        bool empty();

    private:
        long long getFather(long long pos);
        long long getLeftChild(long long pos);
        long long getRightChild(long long pos);

        long long size;
        T* data;

        void heapifyDown(long long pos);
        void heapifyUp(long long pos);
};


#endif