#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "tuple.hpp"

class Comp_Lost_Woods {

    public:
        bool operator() (const double& v1, const double& v2) const;

};

#endif