#include "hash.hpp"

long long Hash_Lost_woods::operator() (const Tuple<long long, long long>& key, const long long &max) const {
    return (max / key.first + key.second);
}