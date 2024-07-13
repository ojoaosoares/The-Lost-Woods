#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include "list.hpp"
#include "node.hpp"

typedef long long ll;

template  <typename T>
class SinglyLinkedList : public  List<T>
{

    protected :
        Node<T>* head;
        Node<T>* tail;
        virtual Node<T>* getPosition(int index, bool before = false) const;
    
    public :

        Iterator<T> begin();
        Iterator<T> end();

        SinglyLinkedList();
        ~SinglyLinkedList();
        
        virtual T getItem(int index) const override;
        virtual T removeBegin() override;
        virtual T removeEnd() override;
        virtual T removeIndex(int index) override;
        virtual int search(T item) const = 0;
        virtual void copyArray(T* array, int size);
        virtual void clear() override;

};


template <typename T>
class Iterator {
    private:
        Node<T>* current;
    public:

        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        Iterator(Node<T>* start);

        reference operator*() const;
        pointer operator->();

        Iterator& operator++();
        Iterator operator++(int);

        template <typename U>
        friend bool operator==(const Iterator<U>& a, const Iterator<U>& b);

        template <typename U>
        friend bool operator!=(const Iterator<U>& a, const Iterator<U>& b);
};


#endif