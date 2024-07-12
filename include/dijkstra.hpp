#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"
#include "tuple.hpp"
#include "utils.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
ll source, ll dest, ll vert, ll portals_allowed);

void explorePaths(Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods> &heap, Tuple<Tuple<ll, ll>, double> &curr_vertice,
SinglyLinkedListUnordered<Tuple<ll, double>> *neigh, Comp_Lost_Woods &comp, bool portals);

#endif