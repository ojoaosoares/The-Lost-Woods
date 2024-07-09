#include "hash.hpp"

template<typename T>
long long Hash_Lost_woods<T>::operator() (const Tuple<Tuple<long long, long long>, T>& key, const long long &max) const {
    return static_cast<std::size_t> (max / key.first.first + key.first.second);
}