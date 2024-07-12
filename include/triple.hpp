#ifndef TRIPLE_HPP
#define TRIPLE_HPP

template<typename T1, typename T2, typename T3>
class Triple {        
    public:

        Triple();
        Triple(T1 first, T2 second, T3 third);

        T1 first;
        T2 second;
        T3 third;

        bool operator==(const Tuple<T1, T2>& other) const;
};

#endif