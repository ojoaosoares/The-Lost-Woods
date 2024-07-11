#include "dijkstra.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
ll source, ll dest, ll vert, ll portals_allowed) {
    
    ll maxElements = (vert*(portals_allowed + 1));
    Tuple<ll, ll> hashparam(vert, portals_allowed + 1);

    Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods,
    Tuple<ll, ll>> priority_queue(maxElements, hashparam);

    Tuple<ll, ll> key(0, 0); double distance = 0;
    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> item, *exist; Comp_Lost_Woods comp;
    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh;

    while (!priority_queue.empty())
    {
        item = priority_queue.remove();

        if (item.first.first == dest)
            break;

        neigh = trail.getNeighboors(item.first.first);

        for (auto it = neigh->begin(); it != neigh->end(); it++)
        {
            key.first = (*it).first; key.second = item.first.second;
            distance = item.second + (*it).second; // update distance

            exist = priority_queue.contains(key);

            if (exist == nullptr)
                priority_queue.insert(key, distance);
            
            else if (comp(distance,exist->second))
                priority_queue.update(key, distance);
                
        }


        if (item.first.second < portals_allowed)
        {
            neigh = portals.getNeighboors(item.first.first);

            for (auto it = neigh->begin(); it != neigh->end(); it++)
            {
                key.first = (*it).first; key.second = item.first.second + 1; // Update portal number
                distance = item.second + (*it).second; // update distance

                exist = priority_queue.contains(key);

                if (exist == nullptr)
                    priority_queue.insert(key, distance);
                
                else if (comp(distance, exist->second))
                    priority_queue.update(key, distance);
                    
            }
        }
        
    }

    return (item.first.first == dest) ? item.second : -1;
}