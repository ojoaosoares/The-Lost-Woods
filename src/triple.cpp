#include "triple.hpp"

template<typename T1, typename T2, typename T3>
Triple<T1, T2, T3>::Triple() : first(T1()), second(T2()), third(T3()) {}

template<typename T1, typename T2, typename T3>
Triple<T1, T2, T3>::Triple(T1 first, T2 second, T3 third) : first(first), second(second), third(third) {}