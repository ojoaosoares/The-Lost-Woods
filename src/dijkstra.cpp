#include "dijkstra.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
ll source, ll dest, ll glades, ll portals_allowed) {
    
    Tuple<ll, ll> hashparam(glades, portals_allowed);

    Heap<Tuple<ll, ll>, double, Comp_Lost_Woods, Hash_Lost_Woods,
    Tuple<ll, ll>> priority_queue(glades*(portals_allowed + 1), hashparam);

    Tuple<ll, ll> key(0, 0);
    double distance = 0;

    priority_queue.insert(key, distance);

    Tuple<Tuple<ll, ll>, double> item;

    Comp_Lost_Woods comp;

    while (!priority_queue.empty())
    {
        item = priority_queue.remove();

        if (item.first.first == dest)
            break;

        SinglyLinkedListUnordered<Tuple<ll, double>> *neigh = trail.getNeighboors(item.first.first);

        for (auto it = neigh->begin(); it != neigh->end(); it++)
        {
            key.first = (*it).first; key.second = item.first.second;
            distance = item.second + (*it).second;

            Tuple<Tuple<ll, ll>, double> *item = priority_queue.contains(key);

            if (item == nullptr)
                priority_queue.insert(key, distance);
            
            else if (comp(distance,item->second))
                priority_queue.update(key, distance);
                
        }


        if (item.first.second < portals_allowed)
        {
            SinglyLinkedListUnordered<Tuple<ll, double>> *neigh_portals = portals.getNeighboors(item.first.first);

            for (auto it = neigh_portals->begin(); it != neigh_portals->end(); it++)
            {
                key.first = (*it).first; key.second = item.first.second + 1;
                distance = item.second;

                Tuple<Tuple<ll, ll>, double> *item = priority_queue.contains(key);

                if (item == nullptr)
                    priority_queue.insert(key, distance);
                
                else if (comp(distance, item->second))
                    priority_queue.update(key, distance);
                    
            }
        }
        
    }

    return item.second;
}