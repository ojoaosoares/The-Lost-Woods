#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "heap.hpp"
#include "tuple.hpp"

typedef long long ll;

#define PATH_TYPE 0
#define PORTAL_TYPE 1

double dijkstra(Graph<Tuple<double, double>, Tuple<double, ll>> &graph, ll source, ll dest, ll vert, ll portals_allowed);

double aStar(Graph<Tuple<double, double>, Tuple<double, ll>> &graph, ll source, ll dest, ll vert, ll portals_allowed);

#endif