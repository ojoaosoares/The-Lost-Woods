#ifndef HASH_HPP
#define HASH_HPP

#include "utils.hpp"
#include "tuple.hpp"

class Hash_Custom {

    private:
        ll vert, portals;

    public:
        Hash_Custom(ll vertice, ll portals);
        ll operator() (const Tuple<ll, ll>& key) const;

};

#endif

