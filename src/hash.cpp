#include "hash.hpp"

Hash_Lost_Woods::Hash_Lost_Woods(Tuple<long long, long long> vertice) : glades(vertice.first), portals(vertice.second) {}

long long Hash_Lost_Woods::operator() (const Tuple<long long, long long>& key) const {
    return (glades * key.first + key.second);
}