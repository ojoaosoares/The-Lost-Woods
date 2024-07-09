#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "singlylinkedlistunordered.hpp"


template <typename Vert, typename Weight>
class Graph
{
    private:
    
        long long vertices_number;
        Vert *vertices;
        SinglyLinkedListUnordered<std::pair<long long, Weight>> *adjacencyLists;
        
        
    public:
        Graph(long long v);
        ~Graph();

        void insertVertice(long long index, Vert item);
        void removeVertice(long long index);
        Vert getVertice(long long index);
        SinglyLinkedListUnordered<std::pair<long long, Weight>>* getNeighboors(long long v);
        void insertEdge(long long v1, long long v2, Weight W);
        void removeEdge(long long v1, long long v2);
        bool isAdjacent(long long v1, long long v2);

};

#endif