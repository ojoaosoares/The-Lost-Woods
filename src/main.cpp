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

void tutorial()
{
    std::cerr << "Instructions\n";
    std::cerr << "\t-h\t\t(show this help message)\n";
    std::cerr << "\t-f <filename>\t(input file containing graph data)\n";
    std::cerr << "\n";
    std::cerr << "Description:\n";
    std::cerr << "  The input file should be formatted as follows:\n";
    std::cerr << "  1. The first line contains three integers:\n";
    std::cerr << "     - n: number of vertices\n";
    std::cerr << "     - m: number of trails\n";
    std::cerr << "     - k: number of portals\n";
    std::cerr << "     (if the code was compiled to test the Al or AM)\n";
    std::cerr << "     - dijkOrAstar: 0 for none, 1 for dijkstra 2 for A* \n";
    std::cerr << "  2. The next n lines contain two floating-point numbers each:\n";
    std::cerr << "     - x: x-coordinate of a vertex\n";
    std::cerr << "     - y: y-coordinate of a vertex\n";
    std::cerr << "  3. The next m lines contain two integers each:\n";
    std::cerr << "     - u: starting vertex of a trail\n";
    std::cerr << "     - v: ending vertex of a trail\n";
    std::cerr << "  4. The next k lines contain two integers each:\n";
    std::cerr << "     - u: starting vertex of a portal\n";
    std::cerr << "     - v: ending vertex of a portal\n";
    std::cerr << "  5. The last line contains:\n";
    std::cerr << "     - s: the amount of energy available (Only if the code was compiled in the default way\n";
    std::cerr << "     - q: number of usable portals (Only if the code was compiled in the default way or dijkOrAstar is 1 or 2)\n";
    std::cerr << "\n";
    std::cerr << "Example:\n";
    std::cerr << "  Input file format example:\n";
    std::cerr << "  4 3 2\n";
    std::cerr << "  1.0 2.0\n";
    std::cerr << "  2.0 3.0\n";
    std::cerr << "  3.0 4.0\n";
    std::cerr << "  4.0 5.0\n";
    std::cerr << "  0 1\n";
    std::cerr << "  1 2\n";
    std::cerr << "  2 3\n";
    std::cerr << "  0 2\n";
    std::cerr << "  1 3\n";
    std::cerr << "  100.5 2\n";
}

#ifdef TEST_ALGS
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

        
        Graph_Ad_List<Tuple<double, double>> wood_list(n);
        Graph_Ad_Matriz<Tuple<double, double>> wood_matriz(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            if (wood_list.verticeExist(coordinates) != -1)
                throw std::invalid_argument("Vertice already exist");

            wood_list.insertVertice(coordinates);
            wood_matriz.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood_list.getVertice(vertices.first), wood_list.getVertice(vertices.second));

            if (wood_matriz.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Path already exist");

            wood_list.insertEdge(vertices.first, vertices.second, distance);
            wood_matriz.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            if (wood_matriz.portalExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood_list.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
            wood_matriz.insertPortal(vertices.first, vertices.second);
        }   

        ll q = k/10; std::cin >> q;

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");

        double *distanceToDest = new double[n];
        for (ll i = 0; i < n; i++)
            distanceToDest[i] = euclidean_distance(wood_list.getVertice(i), wood_list.getVertice(n - 1));
        //distance to destiny array

        SinglyLinkedListUnordered<ll> dijkstraPath, aStarPath;
        double output;

        std::cout << std::fixed << std::setprecision(10);

        std::cout << "Adjacency list tests\n";

        std::chrono::duration<double> duration;

        auto start = std::chrono::high_resolution_clock::now();
    
        output = dijkstra_ad_list(wood_list, 0, n-1, q, dijkstraPath);

        auto end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tDijkstra: " << duration.count() << " seconds" << std::endl;
        std::cout << "\tPath size: " << output << '\n';
        std::cout << "\tPath found: ";

        for (auto it = dijkstraPath.begin(); it != dijkstraPath.end(); it++)
            std::cout << *it << ' ';
        
        std::cout << '\n';

        start = std::chrono::high_resolution_clock::now();

        output = aStar_ad_list(wood_list, 0, n-1, q, distanceToDest,aStarPath);

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tA*: " << duration.count() << " seconds" << std::endl;
        std::cout << "\tPath size: " << output << '\n';
        std::cout << "\tPath found: ";

        for (auto it = aStarPath.begin(); it != aStarPath.end(); it++)
            std::cout << *it << ' ';
        
        std::cout << '\n';

        aStarPath.clear();
        dijkstraPath.clear();

        std::cout << "Adjacency matriz tests\n";

        start = std::chrono::high_resolution_clock::now();
    
        output = dijkstra_ad_matriz(wood_matriz, 0, n-1, q, dijkstraPath);

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tDijkstra: " << duration.count() << " seconds" << std::endl;
        std::cout << "\tPath size: " << output << '\n';
        std::cout << "\tPath found: ";

        for (auto it = dijkstraPath.begin(); it != dijkstraPath.end(); it++)
            std::cout << *it << ' ';

        std::cout << '\n';

        start = std::chrono::high_resolution_clock::now();

        output = aStar_ad_matriz(wood_matriz, 0, n-1, q, distanceToDest, aStarPath);

        end = std::chrono::high_resolution_clock::now();

        duration = end - start;

        std::cout << "\tA*: " << duration.count() << " seconds" << std::endl;
        std::cout << "\tPath size: " << output << '\n';
        std::cout << "\tPath found: ";

        for (auto it = aStarPath.begin(); it != aStarPath.end(); it++)
            std::cout << *it << ' ';
        
        std::cout << '\n';

        delete[] distanceToDest;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        tutorial();
    }
}

#elif TEST_LIST_SPACE

int main() {
    
    try
    {    
        ll n = 0, m = 0, k = 0, dijkOrAstar = 0; 
        std::cin >> n >> m >> k >> dijkOrAstar;

        if(n <= 0)
            throw std::domain_error("Vertices number cannot be negative or zero");

        if(m < 0)
            throw std::domain_error("Paths number cannot be negative");

        if(k < 0)
            throw std::domain_error("Portals number cannot be negative");

        if (dijkOrAstar != NONE_TEST_CODE && dijkOrAstar != DIJKSTRA_TEST_CODE && dijkOrAstar != ASTAR_TEST_CODE)
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

            if (wood_list.portalExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood_list.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        ll q = 0; std::cin >> q;

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");

        if (dijkOrAstar == DIJKSTRA_TEST_CODE)
        {
            SinglyLinkedListUnordered<ll> dijkstraPath;

            dijkstra_ad_list(wood_list, 0, n-1, q, dijkstraPath);
        }

        else if(dijkOrAstar == ASTAR_TEST_CODE)
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


#elif TEST_MATRIZ_SPACE

int main() {
    
    try
    {    
        ll n = 0, m = 0, k = 0, dijkOrAstar = 0; 
        std::cin >> n >> m >> k >> dijkOrAstar;

        if(n <= 0)
            throw std::domain_error("Vertices number cannot be negative or zero");

        if(m < 0)
            throw std::domain_error("Paths number cannot be negative");

        if(k < 0)
            throw std::domain_error("Portals number cannot be negative");

        if (dijkOrAstar != NONE_TEST_CODE && dijkOrAstar != DIJKSTRA_TEST_CODE && dijkOrAstar != ASTAR_TEST_CODE)
        {
            throw std::domain_error("Invalid test 0 for none type 1 for dijkstra 2 for A*");
        }
        
        Graph_Ad_Matriz<Tuple<double, double>> wood_matriz(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            if (wood_matriz.verticeExist(coordinates) != -1)
                throw std::invalid_argument("Vertice already exist");

            wood_matriz.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood_matriz.getVertice(vertices.first), wood_matriz.getVertice(vertices.second));

            if (wood_matriz.edgeExist(vertices.first, vertices.second))
                throw std::invalid_argument("Path already exist");

            wood_matriz.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            if (wood_matriz.portalExist(vertices.first, vertices.second))
                throw std::invalid_argument("Portal already exist");

            wood_matriz.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        ll q = 0; std::cin >> q;

        if(q < 0 || q > k)
            throw std::domain_error("Invalid maximum of portals");


        if(dijkOrAstar == DIJKSTRA_TEST_CODE)
        {
            SinglyLinkedListUnordered<ll> dijkstraPath;

            dijkstra_ad_matriz(wood_matriz, 0, n-1, q, dijkstraPath);
        }

        else if (dijkOrAstar == ASTAR_TEST_CODE)
        {
            double *distanceToDest = new double[n];
            for (ll i = 0; i < n; i++)
                distanceToDest[i] = euclidean_distance(wood_matriz.getVertice(i), wood_matriz.getVertice(n - 1));

            SinglyLinkedListUnordered<ll> aStarPath;

            aStar_ad_matriz(wood_matriz, 0, n-1, q, distanceToDest, aStarPath);

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
        
        Graph_Ad_List<Tuple<double, double>> wood(n);

        for (size_t i = 0; i < n; i++)
        {
            Tuple<double, double> coordinates;
            std::cin >> coordinates.first >> coordinates.second;

            // if (wood.verticeExist(coordinates) != -1)
            //     throw std::invalid_argument("Vertice already exist");

            wood.insertVertice(coordinates);
        }
        
        for (size_t i = 0; i < m; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            double distance = euclidean_distance(wood.getVertice(vertices.first), wood.getVertice(vertices.second));

            // if (wood.edgeExist(vertices.first, vertices.second))
            //     throw std::invalid_argument("Path already exist");

            wood.insertEdge(vertices.first, vertices.second, distance);
        }

        for (size_t i = 0; i < k; i++)
        {
            Tuple<ll, ll> vertices;
            std::cin >> vertices.first >> vertices.second;

            // if (wood.portalExist(vertices.first, vertices.second))
            //     throw std::invalid_argument("Portal already exist");

            wood.insertEdge(vertices.first, vertices.second, PORTAL_TYPE);
        }   

        double s = 105; ll q = k/10;

        std::cin >> s >> q;

        if(s < 0)
            throw std::domain_error("Energy cannot be negative");

        if(q < 0)
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

        tutorial();
    }
}

#endif