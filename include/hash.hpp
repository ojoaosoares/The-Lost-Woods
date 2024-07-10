#ifndef HASH_HPP
#define HASH_HPP

#include "tuple.hpp"

class Hash_Lost_woods {

    public:
        long long operator() (const Tuple<long long, long long>& key, const long long &max) const;

};

#endif

