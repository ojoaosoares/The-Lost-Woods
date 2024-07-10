#include "comparator.hpp"

template<typename T>
bool Comp_Lost_Woods<T>::operator() (const T& v1, const T& v2) const {
    return (v1 < v2);
}

template class Comp_Lost_Woods<double>;