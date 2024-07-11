#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "tuple.hpp"
#include "utils.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
ll source, ll dest, ll vert, ll portals_allowed);

#endif