#include <iostream>
#include "heap.hpp"
#include "graph.hpp"
#include "utils.hpp"
#include "euclidean_distance.hpp"
#include "dijkstra.hpp"
#include "astar.hpp"
#include <chrono>
#include <iomanip>

int main() {

    ll n, m, k; 
    std::cin >> n >> m >> k;

    Graph<Tuple<double, double>, Tuple<double, ll>> wood(n);

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

    auto inicio = std::chrono::high_resolution_clock::now();
    double dijkstra_output = dijkstra(wood, 0, n-1, n, q);
    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracao_dijstra = fim - inicio;    

    inicio = std::chrono::high_resolution_clock::now();
    double astar_output = aStar(wood, 0, n-1, n, q);
    fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracao_astar = fim - inicio;

    std::cout << "Dijkstra\n";
    std::cout << "Caminho encontrado: " << dijkstra_output << " energia\n";
    std::cout << std::fixed << std::setprecision(7) << "Tempo de execução: " << duracao_dijstra.count() << " segundosz\n";

    std::cout.unsetf(std::ios::fixed);

    std::cout << "A Star\n";
    std::cout << "Caminho encontrado: " << astar_output << " energia\n";
    std::cout << std::fixed << std::setprecision(7) << "Tempo de execução: " << duracao_astar.count() << " segundosz\n";

}