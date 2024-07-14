#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "singlylinkedlistunordered.hpp"
#include "tuple.hpp"

typedef long long ll;

template <typename Vert, typename Weight>
class Graph
{
    private:
    
        ll vertices_number;
        Vert *vertices;
        SinglyLinkedListUnordered<Tuple<ll, Weight>> *adjacencyLists;
        
        
    public:
        Graph(ll v);
        ~Graph();

        void insertVertice(ll index, Vert item);
        Vert getVertice(ll index);
        SinglyLinkedListUnordered<Tuple<ll, Weight>>* getNeighboors(ll v);
        void insertEdge(ll v1, ll v2, Weight W);
        bool isAdjacent(ll v1, ll v2);

};

#endif