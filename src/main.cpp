#include <iostream>
#include "heap.hpp"
#include "graph.hpp"
#include "utils.hpp"
#include "euclidean_distance.hpp"
#include "dijkstra.hpp"

int main() {

    ll n, m, k; 
    std::cin >> n >> m >> k;

    Graph<Tuple<double, double>, double> trail(n);
    Graph<Tuple<double, double>, double> portals(n);

    for (size_t i = 0; i < n; i++)
    {
        Tuple<double, double> coordinates;
        std::cin >> coordinates.first >> coordinates.second;

        trail.insertVertice(i, coordinates);
        portals.insertVertice(i, coordinates);
    }
    

    for (size_t i = 0; i < m; i++)
    {
        Tuple<ll, ll> vertices;
        std::cin >> vertices.first >> vertices.second;

        trail.insertEdge(vertices.first, vertices.second, euclidean_distance(trail.getVertice(vertices.first), trail.getVertice(vertices.second)));
    }

    for (size_t i = 0; i < k; i++)
    {
        Tuple<ll, ll> vertices;
        std::cin >> vertices.first >> vertices.second;

        portals.insertEdge(vertices.first, vertices.second, 0);
    }   

    double s; ll q;
    std::cin >> s >> q;

    std::cout << dijkstra(trail, portals, 0, n-1, n, q) << '\n';
    
}