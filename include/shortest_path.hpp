#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "graph.hpp"
#include "heap.hpp"
#include "tuple.hpp"

typedef long long ll;

#define PATH_TYPE 0
#define PORTAL_TYPE 1

double dijkstra_ad_list(const Graph_Ad_List<Tuple<double, double>, Tuple<double, ll>> &graph, const ll &source, const ll &dest, const ll &vert, const ll &portals_allowed);

double aStar_ad_list(const Graph_Ad_List<Tuple<double, double>, Tuple<double, ll>> &graph, const ll &source, const ll &dest, const ll &vert, const ll &portals_allowed);

double dijkstra_ad_matrix(const Graph_Ad_Matrix<Tuple<double, double>, Tuple<double, ll>> &graph, const ll &source, const ll &dest, const ll &vert, const ll &portals_allowed);

double aStar_ad_matrix(const Graph_Ad_Matrix<Tuple<double, double>, Tuple<double, ll>> &graph, const ll &source, const ll &dest, const ll &vert, const ll &portals_allowed);

#endif