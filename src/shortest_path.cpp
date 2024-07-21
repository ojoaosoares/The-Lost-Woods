#include "shortest_path.hpp"
#include "euclidean_distance.hpp"

double dijkstra_ad_list(const Graph_Ad_List<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, SinglyLinkedListUnordered<ll> &path) {
    
    const ll vert = graph.getVerticesNumber();
    const ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals

    const Comp_Dijkstra comp; // A simple double comparator
    const Hash_Custom hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals

    Heap<Tuple<ll, ll>, double, Comp_Dijkstra, Hash_Custom> priority_queue(maxElements, comp, hash);

    Tuple<ll, ll> key(source, 0); double distance = 0;
    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> curr_vertice, *exist = nullptr; 
    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh = nullptr;

    Tuple<bool, Tuple<ll, ll>> *visited = new Tuple<bool, Tuple<ll, ll>>[maxElements]; 
    for (ll i = 0; i < maxElements; i++)
    {
        visited[i].first = false;
        visited[i].second.first = -1;
    }
        
    // Initialazing the visited array

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        for (ll i = curr_vertice.first.second; i < portals_allowed; i++)
        {
            key = curr_vertice.first;
            key.second = i;

            if (visited[hash(key)].first == true) break;
            else visited[hash(key)].first = true;
        }
        
        if (curr_vertice.first.first == dest)
            break;

        neigh = graph.getNeighboors(curr_vertice.first.first);

        for (auto edge = neigh->begin(); edge != neigh->end(); edge++)
        {
            key.first = edge->first; 
            key.second = curr_vertice.first.second;

            if (edge->second == PORTAL_TYPE)
                key.second++; // If were analyzing the portals, we increment the number of portals used 

            if (key.second > portals_allowed || visited[hash(key)].first) // First we verify if the number of portals used doesn't exceed the limit
                continue; 

            distance = curr_vertice.second + edge->second; // update distance

            exist = priority_queue.contains(key);

            if (exist == nullptr)
            {
                priority_queue.insert(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
            
            else if (distance < exist->second)
            {
                priority_queue.update(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
                
        }
    }

    Tuple<ll, ll> atual = curr_vertice.first;
    while (atual.first != -1) {
        path.insertBegin(atual.first);
        atual = visited[hash(atual)].second;
    }

    delete[] visited;

    return (curr_vertice.first.first == dest) ? curr_vertice.second : -1;
}


double aStar_ad_list(const Graph_Ad_List<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, double *distanceToDest ,SinglyLinkedListUnordered<ll> &path) {
    
    const ll vert = graph.getVerticesNumber();
    const ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals

    const Comp_A_Star comp; // A simple double comparator
    const Hash_Custom hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals
    
    Heap<Tuple<ll, ll>, Tuple<double, double>, Comp_A_Star, Hash_Custom> priority_queue(maxElements, comp, hash);

    Tuple<bool, Tuple<ll, ll>> *visited = new Tuple<bool, Tuple<ll, ll>>[maxElements]; 
    for (ll i = 0; i < maxElements; i++)
    {
        // Visited array
        visited[i].first = false;
        visited[i].second.first = -1;
    }

    Tuple<ll, ll> key(source, 0);
    Tuple<double, double> distance(0, distanceToDest[key.first]);

    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, Tuple<double, double>> curr_vertice, *exist = nullptr; 
    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh = nullptr;

    
    // Initialazing the visited array

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        for (ll i = curr_vertice.first.second; i < portals_allowed; i++)
        {
            key = curr_vertice.first;
            key.second = i;

            if (visited[hash(key)].first == true) break;
            else visited[hash(key)].first = true;
        }

        if (curr_vertice.first.first == dest)
            break;

        neigh = graph.getNeighboors(curr_vertice.first.first);

        for (auto edge = neigh->begin(); edge != neigh->end(); edge++)
        {
            key.first = edge->first; 
            key.second = curr_vertice.first.second;

            if (edge->second == PORTAL_TYPE)
                key.second++; // If were analyzing the portals, we increment the number of portals used 

            if (key.second > portals_allowed || visited[hash(key)].first) // First we verify if the number of portals used doesn't exceed the limit
                continue; 

            distance.first = curr_vertice.second.first + edge->second; // update distance
            distance.second = distanceToDest[key.first];

            exist = priority_queue.contains(key);

            if (exist == nullptr)
            {   
                priority_queue.insert(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
            
            else if (distance.first < exist->second.first)
            {
                priority_queue.update(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
                
        }
    }

    Tuple<ll, ll> atual = curr_vertice.first;
    while (atual.first != -1) {
        path.insertBegin(atual.first);
        atual = visited[hash(atual)].second;
    }

    delete[] visited;

    return (curr_vertice.first.first == dest) ? curr_vertice.second.first : -1;
}


double dijkstra_ad_matrix(Graph_Ad_Matrix<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, SinglyLinkedListUnordered<ll> &path) {
    
    const ll vert = graph.getVerticesNumber();
    const ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals

    const Comp_Dijkstra comp; // A simple double comparator
    const Hash_Custom hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals
    
    Heap<Tuple<ll, ll>, double, Comp_Dijkstra, Hash_Custom> priority_queue(maxElements, comp, hash);

    Tuple<ll, ll> key(source, 0); double distance = 0;
    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> curr_vertice, *exist = nullptr; 
    double *neigh = nullptr;

    Tuple<bool, Tuple<ll, ll>> *visited = new Tuple<bool, Tuple<ll, ll>>[maxElements]; 

    for (ll i = 0; i < maxElements; i++)
    {
        visited[i].first = false;
        visited[i].second.first = -1;
    }
    // Initialazing the visited array

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        for (ll i = curr_vertice.first.second; i < portals_allowed; i++)
        {
            key = curr_vertice.first;
            key.second = i;

            if (visited[hash(key)].first == true) break;
            else visited[hash(key)].first = true;
        }

        if (curr_vertice.first.first == dest)
            break;

        neigh = graph.getNeighboors(curr_vertice.first.first);

        for (ll vert = 0; vert < graph.getVerticesNumber(); vert++)
        {
            key.first = vert; 
            key.second = curr_vertice.first.second;

            if (neigh[vert] == PORTAL_TYPE)
                key.second++; // If were analyzing the portals, we increment the number of portals used 

            if (visited[hash(key)].first || neigh[vert] < 0 || key.second > portals_allowed) // First we verify if the number of portals used doesn't exceed the limit
                continue; 

            distance = curr_vertice.second + neigh[vert]; // update distance

            exist = priority_queue.contains(key);

            if (exist == nullptr)
            {
                priority_queue.insert(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
            
            else if (distance < exist->second)
            {
                priority_queue.update(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
                
        }
    }

    Tuple<ll, ll> atual = curr_vertice.first;
    while (atual.first != -1) {
        path.insertBegin(atual.first);
        atual = visited[hash(atual)].second;
    }

    delete[] visited;    

    return (curr_vertice.first.first == dest) ? curr_vertice.second : -1;
}


double aStar_ad_matrix(Graph_Ad_Matrix<Tuple<double, double>> &graph, const ll &source, const ll &dest, const ll &portals_allowed, double *distanceToDest, SinglyLinkedListUnordered<ll> &path)
{    
    const ll vert = graph.getVerticesNumber();
    const ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals

    const Comp_A_Star comp; // A simple double comparator
    const Hash_Custom hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals
    
    Heap<Tuple<ll, ll>, Tuple<double, double>, Comp_A_Star, Hash_Custom> priority_queue(maxElements, comp, hash);

    Tuple<bool, Tuple<ll, ll>> *visited = new Tuple<bool, Tuple<ll, ll>>[maxElements]; 
    for (ll i = 0; i < maxElements; i++)
    {
        // Visited array
        visited[i].first = false;
        visited[i].second.first = -1;
    }

    Tuple<ll, ll> key(source, 0);
    Tuple<double, double> distance(0, distanceToDest[key.first]);

    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, Tuple<double, double>> curr_vertice, *exist = nullptr; 
    double *neigh = nullptr;

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        for (ll i = curr_vertice.first.second; i < portals_allowed; i++)
        {
            key = curr_vertice.first;
            key.second = i;

            if (visited[hash(key)].first == true) break;
            else visited[hash(key)].first = true;
        }

        if (curr_vertice.first.first == dest)
            break;

        neigh = graph.getNeighboors(curr_vertice.first.first);

        for (ll vert = 0; vert < graph.getVerticesNumber(); vert++)
        {
            key.first = vert; 
            key.second = curr_vertice.first.second;

            if (neigh[vert] == PORTAL_TYPE)
                key.second++; // If were analyzing the portals, we increment the number of portals used 

            if (neigh[vert] < 0  || visited[hash(key)].first ||key.second > portals_allowed) // First we verify if the number of portals used doesn't exceed the limit
                continue; 

            distance.first = curr_vertice.second.first + neigh[vert]; // update distance
            distance.second = distanceToDest[key.first];

            exist = priority_queue.contains(key);

            if (exist == nullptr)
            {   
                priority_queue.insert(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
            
            else if (distance.first < exist->second.first)
            {
                priority_queue.update(key, distance);
                visited[hash(key)].second = curr_vertice.first;
            }
                
        }
    }

    Tuple<ll, ll> atual = curr_vertice.first;
    while (atual.first != -1) {
        path.insertBegin(atual.first);
        atual = visited[hash(atual)].second;
    }

    delete[] visited;

    return (curr_vertice.first.first == dest) ? curr_vertice.second.first : -1;
}