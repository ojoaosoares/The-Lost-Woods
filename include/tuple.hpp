#ifndef TUPLE_HPP
#define TUPLE_HPP

template<typename T1,typename T2>
class Tuple {        
    public:

        Tuple();
        Tuple(T1 first, T2 second);

        T1 first;
        T2 second;

        bool operator==(const Tuple<T1, T2>& other) const;
};

#endif