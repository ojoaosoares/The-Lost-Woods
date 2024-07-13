#include "hash.hpp"

Hash_Custom::Hash_Custom(ll vertice, ll portals) : vert(vertice), portals(portals) {}

ll Hash_Custom::operator() (const Tuple<ll, ll>& key) const {
    return (portals * key.first + key.second);
}