#ifndef TRIPLE_HPP
#define TRIPLE_HPP

template<typename T1, typename T2, typename T3>
class Triple {        
    public:

        Triple();
        Triple(T1 first, T2 second, T3 third);

        T1 first;
        T2 second;
        T3 third.
};

template<typename T>
class Hash_Triple_Lost_woods {

    public:
        long long operator() (const Triple<long long, long long, T>& key,const long long &max) const;

};

#endif