#include "comparator.hpp"

template<typename T>
bool Comp_Lost_woods<T>::operator() (const T& v1, const T& v2) const {
    return (v1 < v2);
}