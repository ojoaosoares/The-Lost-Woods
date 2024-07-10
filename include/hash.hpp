#ifndef HASH_HPP
#define HASH_HPP

#include "tuple.hpp"

class Hash_Lost_Woods {

    private:
        long long glades, portals;

    public:
        Hash_Lost_Woods(Tuple<long long, long long> vertice);
        long long operator() (const Tuple<long long, long long>& key) const;

};

#endif

