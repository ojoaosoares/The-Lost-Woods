#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "singlylinkedlistunordered.hpp"


template <typename T, typename Weight>
class Graph
{
    private:
        T *vertices;
        SinglyLinkedListUnordered<std::pair<long long, Weight>> *adjacencyLists;
        long long vertices_number;
        
    public:
        Graph(long long v);
        ~Graph();

        void insertVertice(long long index, T item);
        void removeVertice(long long index);
        T getVertice(long long index);
        SinglyLinkedListUnordered<std::pair<long long, Weight>>* getNeighboors(long long v);
        void insertEdge(long long v1, long long v2, Weight W);
        void removeEdge(long long v1, long long v2);
        bool isAdjacent(long long v1, long long v2);

};

#endif