#include "tuple.hpp"

template<typename T1,typename T2>
Tuple<T1, T2>::Tuple() : first(T1()), second(T2()) {}

template<typename T1,typename T2>
Tuple<T1, T2>::Tuple(T1 first, T2 second) : first(first), second(second) {}

template<typename T1, typename T2>
bool Tuple<T1, T2>::operator==(const Tuple<T1, T2>& other) const {
    return (this->first == other.first && this->second == other.second);
}

template class Tuple<ll, ll>; 
template class Tuple<ll, double>;
template class Tuple<double, double>;
template class Tuple<Tuple<ll, ll>, double>;
template class Tuple<Tuple<ll, ll>, Tuple<double, double>>;
template class Tuple<bool, Tuple<ll, ll>>;