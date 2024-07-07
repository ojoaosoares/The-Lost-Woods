#ifndef SINGLY_LINKED_LIST_UNORDERED
#define SINGLY_LINKED_LIST_UNORDERED


#include "singlylinkedlist.hpp"

template  <typename T>
class SinglyLinkedListUnordered : public  SinglyLinkedList<T>
{   
    public :
        SinglyLinkedListUnordered();
        ~SinglyLinkedListUnordered();

        void setItem(T item, int index);
        void insertBegin(T item);
        void insertEnd(T item);
        void insertIndex(T item, int index);
        int search(T item) const override;

};

#endif