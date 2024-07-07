#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "singlylinkedlistunordered.hpp"


template <typename T, typename Weight>
class Graph
{
    private:
        T *vertices;
        SinglyLinkedListUnordered<std::pair<long long, Weight>> *adjacencyLists;
        
    public:
        Graph(long long v);
        ~Graph();

        void insertVertice(long long index, T item);
        void insertEdge(long long v1, long long v2, Weight W);
        bool isAdjacent(long long v1, long long v2, Weight W);

};

#endif