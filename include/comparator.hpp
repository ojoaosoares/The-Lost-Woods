#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP

#include "utils.hpp"
#include "tuple.hpp"

class Comp_Lost_Woods {

    public:
        bool operator() (const Tuple<Tuple<ll, ll>, double>& v1, const Tuple<Tuple<ll, ll>, double>& v2) const;

};

class Comp_A_Star {



    public:
        Comp_A_Star(ll max, double *dist);
        ~Comp_A_Star();

        ll max;
        double *distances;
        bool operator() (const Tuple<Tuple<ll, ll>, double>& v1, const Tuple<Tuple<ll, ll>, double>& v2) const;
};

#endif