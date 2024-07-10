#ifndef HASH_HPP
#define HASH_HPP

#include "tuple.hpp"
#include "utils.hpp"

class Hash_Lost_Woods {

    private:
        ll glades, portals;

    public:
        Hash_Lost_Woods(Tuple<ll, ll> vertice);
        ll operator() (const Tuple<ll, ll>& key) const;

};

#endif

