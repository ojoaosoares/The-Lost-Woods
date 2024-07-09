#include "tuple.hpp"

template<typename T1,typename T2>
Tuple<T1, T2>::Tuple() : first(T1()), second(T2()) {}

template<typename T1,typename T2>
Tuple<T1, T2>::Tuple(T1 first, T2 second) : first(first), second(second) {}