#include "dijkstra.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"

double dijkstra(Graph<Tuple<long long, long long>, double> graph, long long source, long long dest) {
    
    Heap<Tuple<long long, long long>, double, Comp_Lost_woods<double>, Hash_Lost_woods> priority_queue();

}