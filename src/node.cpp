#include "node.hpp"
#include <utility>
// Node implementation

template <typename T>
Node<T>::Node(T item) : item(item), next(nullptr) {}

template class Node<long long>;
template class Node<int>;
template class Node<double>;

template class Node<std::pair<long long, long long>>;
template class Node<std::pair<long long, int>>;
template class Node<std::pair<long long, double>>;
template class Node<std::pair<double, double>>;