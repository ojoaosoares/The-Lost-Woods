#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "utils.hpp"
#include "tuple.hpp"

class Comp_Lost_Woods {

    public:
        bool operator() (const double& v1, const double& v2) const;

};

class Comp_A_Star {



    public:
        bool operator() (const Tuple<double, double>& v1, const Tuple<double, double>& v2) const;
};

#endif