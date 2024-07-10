#include <iterator.hpp>
#include "tuple.hpp"
#include "utils.hpp"

template <typename T>
Iterator<T>::Iterator(Node<T>* start) : current(start) {}

template <typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const {
    return current->item;
}

template <typename T>
typename Iterator<T>::pointer Iterator<T>::operator->() {
    return &(current->item);
}

template <typename T>
Iterator<T>& Iterator<T>::operator++() {
    current = current->next;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
bool operator==(const Iterator<T>& a, const Iterator<T>& b) {
    return a.current == b.current;
}

template <typename T>
bool operator!=(const Iterator<T>& a, const Iterator<T>& b) {
    return a.current != b.current;
}



template class Iterator<Tuple<ll, double>>;

template bool operator==(const Iterator<Tuple<ll, double>>& a, const Iterator<Tuple<ll, double>>& b);
template bool operator!=(const Iterator<Tuple<ll, double>>& a, const Iterator<Tuple<ll, double>>& b);