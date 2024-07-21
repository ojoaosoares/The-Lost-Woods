#include <iostream>
#include "heap.hpp"
#include "graph.hpp"
#include "euclidean_distance.hpp"
#include "shortest_path.hpp"
#include <chrono>
#include <iomanip>

typedef long long ll;

#define NONE_TEST_CODE 0
#define DIJKSTRA_TEST_CODE 1
#define ASTAR_TEST_CODE 2

#ifdef TEST_LIST_MATRIX

int main() {
    
    try
    {    
        ll n = 0, m = 0, k = 0; 
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

        ll q = 0; std::cin >> q;

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");

        double *distanceToDest = new double[n];
        for (ll i = 0; i < n; i++)
            distanceToDest[i] = euclidean_distance(wood_list.getVertice(i), wood_list.getVertice(n - 1));
        //distance to destiny array

        SinglyLinkedListUnordered<ll> dijkstraPath, aStarPath;

        std::cout << std::fixed << std::setprecision(10);

        std::cout << "Adjacency list tests\n";

        std::chrono::duration<double> duration;

        auto start = std::chrono::high_resolution_clock::now();
    
        std::cout << dijkstra_ad_list(wood_list, 0, n-1, q, dijkstraPath) << '\n';

        auto end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tDijkstra: " << duration.count() << " seconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();

        std::cout << aStar_ad_list(wood_list, 0, n-1, q, distanceToDest,aStarPath) << '\n';

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tA*: " << duration.count() << " seconds" << std::endl;


        std::cout << "Adjacency matrix tests\n";

        start = std::chrono::high_resolution_clock::now();
    
        std::cout << dijkstra_ad_matrix(wood_matrix, 0, n-1, q, dijkstraPath) << '\n';

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tDijkstra: " << duration.count() << " seconds" << std::endl;

        start = std::chrono::high_resolution_clock::now();

        std::cout << aStar_ad_matrix(wood_matrix, 0, n-1, q, distanceToDest, aStarPath) << '\n';

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tA*: " << duration.count() << " seconds" << std::endl;

        delete[] distanceToDest;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

#elif TEST_LIST_SPACE

int main() {
    
    try
    {    
        ll n = 0, m = 0, k = 0, dikOrAstar = 0; 
        std::cin >> n >> m >> k >> dikOrAstar;

        if(n <= 0)
            throw std::domain_error("Vertices number cannot be negative or zero");

        if(m < 0)
            throw std::domain_error("Paths number cannot be negative");

        if(k < 0)
            throw std::domain_error("Portals number cannot be negative");

        if ((m + k) > n * (n - 1))
            throw std::domain_error("Maximum number of edges in a simple directed graph exced");

        if (dikOrAstar != NONE_TEST_CODE && dikOrAstar != DIJKSTRA_TEST_CODE && dikOrAstar != ASTAR_TEST_CODE)
        {
            throw std::domain_error("Invalid test 0 for none type 1 for dijkstra 2 for A*");
        }
            
        Graph_Ad_List<Tuple<double, double>> wood_list(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            if (wood_list.verticeExist(coordinates) != -1)
                throw std::invalid_argument("Vertice already exist");

            wood_list.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood_list.getVertice(vertices.first), wood_list.getVertice(vertices.second));

            if (wood_list.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Path already exist");

            wood_list.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            if (wood_list.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood_list.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        ll q = 0; std::cin >> q;

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");

        if (dikOrAstar == DIJKSTRA_TEST_CODE)
        {
            SinglyLinkedListUnordered<ll> dijkstraPath;

            dijkstra_ad_list(wood_list, 0, n-1, q, dijkstraPath);
        }

        else if(dikOrAstar == ASTAR_TEST_CODE)
        {
            double *distanceToDest = new double[n];
            for (ll i = 0; i < n; i++)
                distanceToDest[i] = euclidean_distance(wood_list.getVertice(i), wood_list.getVertice(n - 1));

            SinglyLinkedListUnordered<ll> aStarPath;

            aStar_ad_list(wood_list, 0, n-1, q, distanceToDest, aStarPath);

            delete[] distanceToDest;
        }

        

    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


#elif TEST_MATRIX_SPACE

int main() {
    
    try
    {    
        ll n = 0, m = 0, k = 0, dikOrAstar = 0; 
        std::cin >> n >> m >> k >> dikOrAstar;

        if(n <= 0)
            throw std::domain_error("Vertices number cannot be negative or zero");

        if(m < 0)
            throw std::domain_error("Paths number cannot be negative");

        if(k < 0)
            throw std::domain_error("Portals number cannot be negative");

        if ((m + k) > n * (n - 1))
            throw std::domain_error("Maximum number of edges in a simple directed graph exced");

        if (dikOrAstar != NONE_TEST_CODE && dikOrAstar != DIJKSTRA_TEST_CODE && dikOrAstar != ASTAR_TEST_CODE)
        {
            throw std::domain_error("Invalid test 0 for none type 1 for dijkstra 2 for A*");
        }
        
        Graph_Ad_Matrix<Tuple<double, double>> wood_matrix(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            if (wood_matrix.verticeExist(coordinates) != -1)
                throw std::invalid_argument("Vertice already exist");

            wood_matrix.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood_matrix.getVertice(vertices.first), wood_matrix.getVertice(vertices.second));

            if (wood_matrix.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Path already exist");

            wood_matrix.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            if (wood_matrix.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood_matrix.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        ll q = 0; std::cin >> q;

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");


        if(dikOrAstar == DIJKSTRA_TEST_CODE)
        {
            SinglyLinkedListUnordered<ll> dijkstraPath;

            dijkstra_ad_matrix(wood_matrix, 0, n-1, q, dijkstraPath);
        }

        else if (dikOrAstar == ASTAR_TEST_CODE)
        {
            double *distanceToDest = new double[n];
            for (ll i = 0; i < n; i++)
                distanceToDest[i] = euclidean_distance(wood_matrix.getVertice(i), wood_matrix.getVertice(n - 1));

            SinglyLinkedListUnordered<ll> aStarPath;

            aStar_ad_matrix(wood_matrix, 0, n-1, q, distanceToDest, aStarPath);

            delete[] distanceToDest;
        }

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
        ll n = 0, m = 0, k = 0; 
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

        double s = 0; ll q = 0;

        std::cin >> s >> q;

        if(s < 0)
            throw std::domain_error("Energy cannot be negative");

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");

        double *distanceToDest = new double[n];
        for (ll i = 0; i < n; i++)
            distanceToDest[i] = euclidean_distance(wood.getVertice(i), wood.getVertice(n - 1));
        //distance to destiny array
        
        SinglyLinkedListUnordered<ll> dijkstraPath, aStarPath;

        std::cout << (dijkstra_ad_list(wood, 0, n-1, q, dijkstraPath) <= s) << '\n';    
        std::cout << (aStar_ad_list(wood, 0, n-1, q, distanceToDest, aStarPath) <= s) << '\n';

        delete[] distanceToDest;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

#endif