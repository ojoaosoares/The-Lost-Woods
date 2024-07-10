#include "dijkstra.hpp"
#include "heap.hpp"
#include "comparator.hpp"
#include "hash.hpp"

double dijkstra(Graph<Tuple<double, double>, double> &trail, Graph<Tuple<double, double>, double> &portals,
long long source, long long dest, long long glades, long long portals_allowed) {
    
    Tuple<long long, long long> hashparam(glades, portals_allowed);

    Heap<Tuple<long long, long long>, double, Comp_Lost_Woods<double>, Hash_Lost_Woods,
    Tuple<long long, long long>> priority_queue(glades*(portals_allowed + 1), hashparam);

    Tuple<long long, long long> key(0, 0);
    double distance = 0;

    priority_queue.insert(key, distance);

    Tuple<Tuple<long long, long long>, double> item;

    Comp_Lost_Woods<double> comp;

    while (!priority_queue.empty())
    {
        item = priority_queue.remove();

        if (item.first.first == dest)
            break;

        SinglyLinkedListUnordered<Tuple<long long, double>> *neigh = trail.getNeighboors(item.first.first);

        for (auto it = neigh->begin(); it != neigh->end(); it++)
        {
            key.first = (*it).first; key.second = item.first.second;
            distance = item.second + (*it).second;

            Tuple<Tuple<long long, long long>, double> *item = priority_queue.contains(key);

            if (item == nullptr)
                priority_queue.insert(key, distance);
            
            else if (comp(distance,item->second))
                priority_queue.update(key, distance);
                
        }


        if (item.first.second < portals_allowed)
        {
            SinglyLinkedListUnordered<Tuple<long long, double>> *neigh_portals = portals.getNeighboors(item.first.first);

            for (auto it = neigh_portals->begin(); it != neigh_portals->end(); it++)
            {
                key.first = (*it).first; key.second = item.first.second + 1;
                distance = item.second;

                Tuple<Tuple<long long, long long>, double> *item = priority_queue.contains(key);

                if (item == nullptr)
                    priority_queue.insert(key, distance);
                
                else if (comp(distance, item->second))
                    priority_queue.update(key, distance);
                    
            }
        }
        
    }

    return item.second;
}