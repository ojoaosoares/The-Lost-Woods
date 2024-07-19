#include <iostream>
#include "heap.hpp"
#include "graph.hpp"
#include "euclidean_distance.hpp"
#include "shortest_path.hpp"
#include <chrono>
#include <iomanip>

typedef long long ll;

#ifdef TEST_LIST_MATRIX

int main() {
    
    try
    {    
        ll n, m, k; 
        std::cin >> n >> m >> k;

        if(n <= 0)
            throw std::domain_error("Vertices number cannot be negative or zero");

        if(m < 0)
            throw std::domain_error("Paths number cannot be negative");

        if(k < 0)
            throw std::domain_error("Portals number cannot be negative");

        if ((m + k) > n * (n - 1))
            throw std::domain_error("Maximum number of edges in a simple directed graph exced");
        
        Graph_Ad_List<Tuple<double, double>> wood_list(n);
        Graph_Ad_Matrix<Tuple<double, double>> wood_matrix(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            if (wood_list.verticeExist(coordinates) != -1)
                throw std::invalid_argument("Vertice already exist");

            wood_list.insertVertice(coordinates);
            wood_matrix.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood_list.getVertice(vertices.first), wood_list.getVertice(vertices.second));

            if (wood_matrix.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Path already exist");

            wood_list.insertEdge(vertices.first, vertices.second, distance);
            wood_matrix.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            if (wood_matrix.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood_list.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
            wood_matrix.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        ll q; std::cin >> q;
        
        if(q < 0)
            throw std::domain_error("Maximum of portals that can be used cannot be negative");

        SinglyLinkedListUnordered<ll> dijkstraPath, aStarPath;

        std::cout << std::fixed << std::setprecision(10);

        std::cout << "Adjacency list tests\n";

        auto start = std::chrono::high_resolution_clock::now();
    
        dijkstra_ad_list(wood_list, 0, n-1, q, dijkstraPath);

        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> duration = end - start;

        std::cout << "\tDijkstra: " << duration.count() << " seconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();

        aStar_ad_list(wood_list, 0, n-1, q, aStarPath);

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tA*: " << duration.count() << " seconds" << std::endl;


        std::cout << "Adjacency matrix tests\n";

        start = std::chrono::high_resolution_clock::now();
    
        dijkstra_ad_matrix(wood_matrix, 0, n-1, q, dijkstraPath);

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tDijkstra: " << duration.count() << " seconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();

        aStar_ad_matrix(wood_matrix, 0, n-1, q, aStarPath);

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tA*: " << duration.count() << " seconds" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}



#else

int main() {
    
    try
    {    
        ll n, m, k; 
        std::cin >> n >> m >> k;

        if(n <= 0)
            throw std::domain_error("Vertices number cannot be negative or zero");

        if(m < 0)
            throw std::domain_error("Paths number cannot be negative");

        if(k < 0)
            throw std::domain_error("Portals number cannot be negative");

        if ((m + k) > n * (n - 1))
            throw std::domain_error("Maximum number of edges in a simple directed graph exced");
        
        Graph_Ad_List<Tuple<double, double>> wood(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            if (wood.verticeExist(coordinates) != -1)
                throw std::invalid_argument("Vertice already exist");

            wood.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood.getVertice(vertices.first), wood.getVertice(vertices.second));

            if (wood.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Path already exist");

            wood.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            if (wood.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        double s; ll q;

        std::cin >> s >> q;

        if(s < 0)
            throw std::domain_error("Energy cannot be negative");

        if(q < 0)
            throw std::domain_error("Maximum of portals that can be used cannot be negative");
        
        SinglyLinkedListUnordered<ll> dijkstraPath, aStarPath;

        std::cout << (dijkstra_ad_list(wood, 0, n-1, q, dijkstraPath) <= s) << '\n';    
        std::cout << (aStar_ad_list(wood, 0, n-1, q, aStarPath) <= s) << '\n';

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

#endif