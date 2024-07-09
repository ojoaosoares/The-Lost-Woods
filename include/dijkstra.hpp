#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "tuple.hpp"

double dijkstra(Graph<Tuple<long long, long long>, double> graph, long long source, long long dest);

#endif