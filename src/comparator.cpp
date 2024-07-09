#include "comparator.hpp"

template<typename T>
bool Comp_Lost_woods<T>::operator() (const Tuple<Tuple<long long, long long>, T>& v1, const Tuple<Tuple<long long, long long>, T>& v2) const {
    return (v1.second < v2.second || v1.second == v2.second && v1.first.second <= v2.first.second);
}