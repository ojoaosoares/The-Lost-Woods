#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"
#include "tuple.hpp"
#include "utils.hpp"

double dijkstra(Graph<Tuple<double, double>, Tuple<double, ll>> &graph, ll source, ll dest, ll vert, ll portals_allowed);

#endif