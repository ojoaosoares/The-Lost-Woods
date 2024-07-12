#include "dijkstra.hpp"

double dijkstra(Graph<Tuple<double, double>, Tuple<double, ll>> &graph, ll source, ll dest, ll vert, ll portals_allowed) {
    
    Comp_Lost_Woods comp; // A simple double comparator
    Hash_Lost_Woods hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals
    ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals
    
    Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods> priority_queue(maxElements, comp, hash);

    Tuple<ll, ll> key(source, 0); double distance = 0;
    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> curr_vertice, *exist; 
    SinglyLinkedListUnordered<Tuple<ll, Tuple<double, ll>>> *neigh;

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        if (curr_vertice.first.first == dest)
            break;

        neigh = graph.getNeighboors(curr_vertice.first.first);

        for (auto edge = neigh->begin(); edge != neigh->end(); edge++)
        {
            key.second = curr_vertice.first.second;

            if (edge->second.second == PORTAL_TYPE)
                key.second++; // If were analyzing the portals, we increment the number of portals used 

            if (key.second > portals_allowed) // First we verify if the number of portals used doesn't exceed the limit
                continue; 
            
            key.first = edge->first; 

            distance = curr_vertice.second + edge->second.first; // update distance

            exist = priority_queue.contains(key);

            if (exist == nullptr)
                priority_queue.insert(key, distance);
            
            else if (comp(distance, exist->second))
                priority_queue.update(key, distance);
                
        }
    }

    return (curr_vertice.first.first == dest) ? curr_vertice.second : -1;
}