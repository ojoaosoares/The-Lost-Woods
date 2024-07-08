#include <iostream>
#include "heap.hpp"
#include "graph.hpp"
#include "euclidean_distance.hpp"

int main() {

    long long n; std::cin >> n;

    Graph<std::pair<double, double>, double> graph(n);

    for (size_t i = 0; i < n; i++)
    {
        std::pair<double, double> coor;
        std::cin >> coor.first >> coor.second;

        graph.insertVertice(i, coor);
    }
    
    long long m; std::cin >> m;

    for (size_t i = 0; i < m; i++)
    {
        std::pair<long long, long long> vertices;
        std::cin >> vertices.first >> vertices.second;

        graph.insertEdge(vertices.first, vertices.second, euclidean_distance(graph.getVertice(vertices.first), graph.getVertice(vertices.second)));
    }

    for (size_t i = 0; i < n; i++)
    {
        SinglyLinkedListUnordered<std::pair<long long, double>> *neigh = graph.getNeighboors(i);

        for (auto it = neigh->begin(); it != neigh->end(); it++)
            std::cout << i << ' ' << (*it).first << ' ' << (*it).second << '\n';
        
    }
}