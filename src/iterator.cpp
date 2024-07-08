#include <iterator.hpp>

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


template class Iterator<long long>;
template class Iterator<int>;
template class Iterator<double>;

template class Iterator<std::pair<long long, long long>>;
template class Iterator<std::pair<long long, int>>;
template class Iterator<std::pair<long long, double>>;

template class Iterator<std::pair<double, double>>;

template bool operator==(const Iterator<long long>& a, const Iterator<long long>& b);
template bool operator==(const Iterator<int>& a, const Iterator<int>& b);
template bool operator==(const Iterator<double>& a, const Iterator<double>& b);

template bool operator!=(const Iterator<long long>& a, const Iterator<long long>& b);
template bool operator!=(const Iterator<int>& a, const Iterator<int>& b);
template bool operator!=(const Iterator<double>& a, const Iterator<double>& b);

template bool operator==(const Iterator<std::pair<long long, long long>>& a, const Iterator<std::pair<long long, long long>>& b);
template bool operator==(const Iterator<std::pair<long long, int>>& a, const Iterator<std::pair<long long, int>>& b);
template bool operator==(const Iterator<std::pair<long long, double>>& a, const Iterator<std::pair<long long, double>>& b);
template bool operator==(const Iterator<std::pair<double, double>>& a, const Iterator<std::pair<double, double>>& b);

template bool operator!=(const Iterator<std::pair<long long, long long>>& a, const Iterator<std::pair<long long, long long>>& b);
template bool operator!=(const Iterator<std::pair<long long, int>>& a, const Iterator<std::pair<long long, int>>& b);
template bool operator!=(const Iterator<std::pair<long long, double>>& a, const Iterator<std::pair<long long, double>>& b);
template bool operator!=(const Iterator<std::pair<double, double>>& a, const Iterator<std::pair<double, double>>& b);