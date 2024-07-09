#include "triple.hpp"
#include <new>

template<typename T1, typename T2, typename T3>
Triple<T1, T2, T3>::Triple() : first(T1()), second(T2()), third(T3()) {}

template<typename T1, typename T2, typename T3>
Triple<T1, T2, T3>::Triple(T1 first, T2 second, T3 third) : first(first), second(second), third(third) {}

template<typename T>
long long Hash_Triple_Lost_woods<T>::operator() (const Triple<long long, long long, T>& key,const long long &max) const {
    return static_cast<std::size_t> (max / key.first + key.second);
}

template<typename T>
bool Comp_Triple_Lost_woods<T>::operator() (const Triple<long long, long long, T>& v1, const Triple<long long, long long, T>& v2) const {
    return (v1.third < v2.third || v1.third == v2.third && v1.second <= v2.second);
}