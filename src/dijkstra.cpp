#include "dijkstra.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
ll source, ll dest, ll vert, ll portals_allowed) {
    
    Comp_Lost_Woods comp; // A simple double comparator
    Hash_Lost_Woods hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals
    ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals
    
    Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods> priority_queue(maxElements, comp, hash);

    Tuple<ll, ll> key(source, 0); double distance = 0;
    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> curr_vertice; 
    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh;

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        if (curr_vertice.first.first == dest)
            break;

        neigh = trail.getNeighboors(curr_vertice.first.first);

        explorePaths(priority_queue, curr_vertice, neigh, comp, false);


        if (curr_vertice.first.second < portals_allowed)
        {
            neigh = portals.getNeighboors(curr_vertice.first.first);

            explorePaths(priority_queue, curr_vertice, neigh, comp, true);
        }
        
    }

    return (curr_vertice.first.first == dest) ? curr_vertice.second : -1;
}


void explorePaths(Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods> &heap, Tuple<Tuple<ll, ll>, double> &curr_vertice,
SinglyLinkedListUnordered<Tuple<ll, double>> *neigh, Comp_Lost_Woods &comp, bool portals) {

    Tuple<ll, ll> key; double distance;
    Tuple<Tuple<ll, ll>, double> *exist;

    for (auto it = neigh->begin(); it != neigh->end(); it++)
    {
        key.first = (*it).first; key.second = curr_vertice.first.second;

        distance = curr_vertice.second + (*it).second; // update distance

        if (portals)
            curr_vertice.first.second++; // If were analyzing the portals, we increment the number of portals used 

        exist = heap.contains(key);

        if (exist == nullptr)
            heap.insert(key, distance);
        
        else if (comp(distance, exist->second))
            heap.update(key, distance);
            
    }
}