#ifndef ITERATOR
#define ITERATOR

#include "node.hpp"
#include <iterator>

template <typename T>
class Iterator {
    private:
        Node<T>* current;
    public:

        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        Iterator(Node<T>* start);

        reference operator*() const;
        pointer operator->();

        Iterator& operator++();
        Iterator operator++(int);

        template <typename U>
        friend bool operator==(const Iterator<U>& a, const Iterator<U>& b);

        template <typename U>
        friend bool operator!=(const Iterator<U>& a, const Iterator<U>& b);
    };

#endif

