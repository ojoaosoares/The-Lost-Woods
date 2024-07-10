#include "tuple.hpp"

template<typename T1,typename T2>
Tuple<T1, T2>::Tuple() : first(T1()), second(T2()) {}

template<typename T1,typename T2>
Tuple<T1, T2>::Tuple(T1 first, T2 second) : first(first), second(second) {}

template<typename T1, typename T2>
bool Tuple<T1, T2>::operator==(const Tuple<T1, T2>& other) const {
    return (this->first == other.first && this->second == other.second);
}

template class Tuple<long long, long long>;
template class Tuple<long long, int>;
template class Tuple<long long, double>;
template class Tuple<double, double>;
template class Tuple<Tuple<long long, long long>, double>;