#include <iostream>
#include "heap.hpp"
#include "graph.hpp"
#include "euclidean_distance.hpp"
#include "shortest_path.hpp"
#include <chrono>
#include <iomanip>

typedef long long ll;

int main() {

    ll n, m, k; 
    std::cin >> n >> m >> k;

    Graph_Ad_List<Tuple<double, double>, Tuple<double, ll>> wood(n);

    for (size_t i = 0; i < n; i++)
    {
        Tuple<double, double> coordinates;
        std::cin >> coordinates.first >> coordinates.second;

        wood.insertVertice(i, coordinates);
    }
    

    for (size_t i = 0; i < m; i++)
    {
        Tuple<ll, ll> vertices;
        std::cin >> vertices.first >> vertices.second;

        double distance = euclidean_distance(wood.getVertice(vertices.first), wood.getVertice(vertices.second));
        Tuple<double, ll> weight(distance, PATH_TYPE);

        wood.insertEdge(vertices.first, vertices.second, weight);
    }

    for (size_t i = 0; i < k; i++)
    {
        Tuple<ll, ll> vertices;
        std::cin >> vertices.first >> vertices.second;

        Tuple<double, ll> weight(0, PORTAL_TYPE);

        wood.insertEdge(vertices.first, vertices.second, weight);
    }   

    double s; ll q;
    std::cin >> s >> q;
    
    std::cout << (dijkstra_ad_list(wood, 0, n-1, n, q) <= s) << '\n';    
    std::cout << (aStar_ad_list(wood, 0, n-1, n, q) <= s) << '\n';    
}