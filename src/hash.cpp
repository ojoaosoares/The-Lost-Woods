#include "hash.hpp"

Hash_Lost_Woods::Hash_Lost_Woods(ll vertice, ll portals) : vert(vertice), portals(portals) {}

ll Hash_Lost_Woods::operator() (const Tuple<ll, ll>& key) const {
    return (portals * key.first + key.second);
}