#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "tuple.hpp"

template<typename T>
class Comp_Lost_woods {

    public:
        bool operator() (const Tuple<Tuple<long long, long long>, T>& v1, const Tuple<Tuple<long long, long long>, T>& v2) const;

};

#endif