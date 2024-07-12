#ifndef HASH_HPP
#define HASH_HPP

#include "utils.hpp"
#include "tuple.hpp"

class Hash_Lost_Woods {

    private:
        ll vert, portals;

    public:
        Hash_Lost_Woods(ll vertice, ll portals);
        ll operator() (const Tuple<ll, ll>& key) const;

};

#endif

