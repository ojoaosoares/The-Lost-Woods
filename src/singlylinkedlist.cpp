#include "singlylinkedlist.hpp"
#include "tuple.hpp"
#include "utils.hpp"

// Singly Linked List implemention

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : List<T>() { head = nullptr; tail = nullptr; }

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() { clear(); }

template <typename T>
Iterator<T> SinglyLinkedList<T>::begin() { return Iterator<T>(head); }

template <typename T>
Iterator<T> SinglyLinkedList<T>::end() { return Iterator<T>(nullptr); }

template <typename T>
Node<T>* SinglyLinkedList<T>::getPosition(int index, bool before) const
{
    // Input : (int) index, the index of the wanted element, (bool) before, if you want the item with the previous index
    // Complexity : Worst case O(n), Best case O(1)

    if (index < 0 || index >= this->getSize()) 
        throw "ERROR: Invalid index";

    Node<T>* p = head;

    for (int i = 0; i < index - 1; i++) p = p->next;
    
    if (!before && index) p = p->next; // And i because 0 has no antecessor

    return p;

}

template <typename T>
T SinglyLinkedList<T>::getItem(int index) const
{
    // Input : (int) index, the index of the wanted element
    // Complexity : Worst case O(n), Best case O(1)

    return getPosition(index)->item;

}

template <typename T>
T SinglyLinkedList<T>::removeBegin()
{
    // Output : T, the item that was removed
    // Complexity : O(1) 

    if(this->Empty())
        throw "ERROR: Empty list";

    Node<T>* p = head;
    head = head->next;

    if (head == nullptr)
        tail = nullptr;

    T aux = p->item;

    delete p;

    this->size--;

    return aux;
}

template <typename T>
T SinglyLinkedList<T>::removeEnd()
{
    // Output : T, the item that was removed
    // Complexity : O(n)

    if(this->Empty())
        throw "ERROR: Empty list";
    
    T aux = tail->item;

    if (this->getSize() == 1)
    {
        delete tail;
        head = nullptr; tail = nullptr;
    }

    else 
    {
        Node<T>* p = getPosition(this->getSize() - 1, true);
        p->next = nullptr;

        delete tail;

        tail = p;
    }
    
    this->size--;

    return aux;    
}

template <typename T>
T SinglyLinkedList<T>::removeIndex(int index)
{
    // Output : T, the item that was removed
    // Complexity : Worst case O(n), best case O(1)

    if (index == 0) 
        return removeBegin();

    if (index == this->getSize() - 1)
        return removeEnd();

    if(this->Empty())
        throw "ERROR: Empty list";
    
    Node<T>* p = getPosition(index, true);
    Node<T>* q = p->next;

    p->next = q->next;

    T aux = q->item;

    delete q;

    this->size--;
    
    return aux;

}

template <typename T>
void SinglyLinkedList<T>::copyArray(T* array, int size)
{
    if (this->size < this->getSize())
        throw "ERROR: size insuficient";

    for (int i = 0; i < this->getSize(); i++)
    {
        Node<T>* p = head;
        array[i] = p->item;
        head = head->next;
        delete p;
    }

    tail = head;
    this->size = 0;
}

template <typename T>
void SinglyLinkedList<T>::clear()
{
    // Complexity : O(n)
    if (!this->Empty())
    {
        Node<T>* p = head;

        while (p != nullptr)
        {
            head = head->next;
            delete p;
            p = head;
        }

        tail = nullptr;

        this->size = 0;
    }
}

template class SinglyLinkedList<Tuple<ll, double>>;
