#ifndef A_STAR_HPP
#define A_STAR_HPP

#include "graph.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"
#include "tuple.hpp"
#include "utils.hpp"

double aStar(Graph<Tuple<double, double>, Tuple<double, ll>> &graph, ll source, ll dest, ll vert, ll portals_allowed);

#endif