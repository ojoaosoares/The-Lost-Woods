#include "hash.hpp"

template<typename T>
long long Hash_Lost_woods<T>::operator() (const Tuple<Tuple<long long, long long>, T>& key, const long long &max) const {
    return (max / key.first.first + key.first.second);
}