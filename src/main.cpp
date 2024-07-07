#include <iostream>
#include "heap.hpp"

int main() {

    long long n; std::cin >> n;

    Heap<long long> heap(n+1);

    for (long long i = 0; i < n; i++)
    {
        long long x; std::cin >> x;
        heap.insert(i, x);
    }

    for (long long i = 0; i < n; i++)
    {
        std::pair<long long, long long> values = heap.remove();
        std::cout << values.second << ' ' << values.first << '\n';
    }

}