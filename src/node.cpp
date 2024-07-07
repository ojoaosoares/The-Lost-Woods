#include "node.hpp"

// Node implementation

template <typename T>
Node<T>::Node(T item) : item(item), next(nullptr) {}

template class Node<long long>;
template class Node<int>;
template class Node<double>;