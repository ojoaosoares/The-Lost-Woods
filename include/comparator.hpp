#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "tuple.hpp"

template<typename T>
class Comp_Lost_Woods {

    public:
        bool operator() (const T& v1, const T& v2) const;

};

#endif