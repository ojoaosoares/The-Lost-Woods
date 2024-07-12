#include "dijkstra.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
ll source, ll dest, ll vert, ll portals_allowed) {
    
    Comp_Lost_Woods comp; // A simple double comparator
    Hash_Lost_Woods hash(vert, portals_allowed + 1); // Possible number of vertices, possible number of portals
    ll maxElements = vert * (portals_allowed + 1); // number of vertices * possible number of portals
    
    Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods> priority_queue(maxElements, comp, hash);

    Tuple<ll, ll> key(source, 0); double distance = 0;
    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> curr_vertice, *exist; 
    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh;

    while (!priority_queue.empty())
    {
        curr_vertice = priority_queue.remove();

        if (curr_vertice.first.first == dest)
            break;

        neigh = trail.getNeighboors(curr_vertice.first.first);

        for (auto it = neigh->begin(); it != neigh->end(); it++)
        {
            key.first = (*it).first; key.second = curr_vertice.first.second;
            distance = curr_vertice.second + (*it).second; // update distance

            exist = priority_queue.contains(key);

            if (exist == nullptr)
                priority_queue.insert(key, distance);
            
            else if (comp(distance,exist->second))
                priority_queue.update(key, distance);
                
        }


        if (curr_vertice.first.second < portals_allowed)
        {
            neigh = portals.getNeighboors(curr_vertice.first.first);

            for (auto it = neigh->begin(); it != neigh->end(); it++)
            {
                key.first = (*it).first; key.second = curr_vertice.first.second + 1; // Update portal number
                distance = curr_vertice.second + (*it).second; // update distance

                exist = priority_queue.contains(key);

                if (exist == nullptr)
                    priority_queue.insert(key, distance);
                
                else if (comp(distance, exist->second))
                    priority_queue.update(key, distance);
                    
            }
        }
        
    }

    return (curr_vertice.first.first == dest) ? curr_vertice.second : -1;
}