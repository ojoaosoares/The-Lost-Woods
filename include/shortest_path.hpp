#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "heap.hpp"
#include "tuple.hpp"

typedef long long ll;

#define PORTAL_TYPE 0

double dijkstra_ad_list(const Graph_Ad_List<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, SinglyLinkedListUnordered<ll> &path);

double aStar_ad_list(const Graph_Ad_List<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, SinglyLinkedListUnordered<ll> &path);

double dijkstra_ad_matrix(Graph_Ad_Matrix<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, SinglyLinkedListUnordered<ll> &path);

double aStar_ad_matrix(Graph_Ad_Matrix<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, SinglyLinkedListUnordered<ll> &path);

#endif