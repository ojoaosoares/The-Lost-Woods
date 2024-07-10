#include "node.hpp"
#include <utility>
#include "tuple.hpp"

// Node implementation

template <typename T>
Node<T>::Node(T item) : item(item), next(nullptr) {}


template class Node<Tuple<long long, double>>;
