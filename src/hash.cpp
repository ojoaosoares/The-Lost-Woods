#include "hash.hpp"

Hash_Lost_Woods::Hash_Lost_Woods(Tuple<ll, ll> vertice) : vert(vertice.first), portals(vertice.second) {}

ll Hash_Lost_Woods::operator() (const Tuple<ll, ll>& key) const {
    return (portals * key.first + key.second);
}