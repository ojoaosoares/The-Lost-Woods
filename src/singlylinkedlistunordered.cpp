#include "singlylinkedlistunordered.hpp"
#include "tuple.hpp"

// Singly Linked List Unordered Implementation


template <typename T>
SinglyLinkedListUnordered<T>::SinglyLinkedListUnordered() : SinglyLinkedList<T>() {}

template  <typename T>
SinglyLinkedListUnordered<T>::~SinglyLinkedListUnordered() {}

template <typename T>
void SinglyLinkedListUnordered<T>::setItem(T item, int index)
{
    // Input : (T) item, the item to be setted, (int) index, the index of the wanted element
    // Complexity : Worst case O(n), Best case O(1)

    this->getPosition(index)->item = item;
}

template <typename T>
void SinglyLinkedListUnordered<T>::insertBegin(T item)
{
    // Input : (T) item, the item to be inserted
    // Complexity : O(1)

    Node<T>* newNode = new Node<T>(item);

    newNode->next = this->head;

    this->head = newNode;

    if (this->Empty()) this->tail = newNode;

    this->size++;

}

template <typename T>
void SinglyLinkedListUnordered<T>::insertEnd(T item)
{
    
    // Input : (T) item, the item to be inserted
    // Complexity : O(1)

    Node<T>* newNode = new Node<T>(item);

    newNode->next = nullptr;

    if (this->Empty())
    {
        this->head = newNode; this->tail = newNode;
    }
    
    else
    {
        this->tail->next = newNode;
        this->tail = newNode;
    }

    this->size++;
}

template <typename T>
void SinglyLinkedListUnordered<T>::insertIndex(T item, int index)
{
    // Input : (T) item, the item to be inserted
    // Complexity : Worst case O(n), best case O(1) 

    if (!index) insertBegin(item);

    else if (this->getSize() == index) insertEnd(item);

    else 
    {
        Node<T>* p = this->getPosition(index, true);
        Node<T>* newNode = new Node<T>(item);
        newNode->next = p->next;
        p->next = newNode;

        this->size++;
    }
    
}

template <typename T>
int SinglyLinkedListUnordered<T>::search(T item) const
{
    // Output : int, the item to be searched
    // Complexity : O(n)

    if(this->Empty())
        throw "ERROR: Empty list";

    Node<T>* p = this->head;

    int i = 0;

    while (p != nullptr)
    {
        if (p->item == item) return i;

        p = p->next;

        i++;
    }

    return -1;

}

template class SinglyLinkedListUnordered<Tuple<long long, double>>;

