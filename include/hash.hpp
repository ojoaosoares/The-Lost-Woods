#ifndef HASH_HPP
#define HASH_HPP

#include "tuple.hpp"

template<typename T>
class Hash_Lost_woods {

    public:
        long long operator() (const Tuple<Tuple<long long, long long>, T>& key, const long long &max) const;

};

#endif

