#include "list.hpp"

// Base List implementation

template <typename T>
List<T>::List() : size(0) {}

template <typename T>
int List<T>::getSize() const
{
    // Output : int, the size of the array
    // Complexity : O(1)

    return size;
}

template <typename T>
bool List<T>::Empty() const
{
    // Output : a boolean value, if the array is empty (size equals 0) true, else false
    // Complexity : O(1)

    return getSize() == 0;
}

template class List<long long>;
template class List<int>;
template class List<double>;