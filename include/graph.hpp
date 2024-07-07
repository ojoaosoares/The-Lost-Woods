#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "singlylinkedlistunordered.hpp"


template <typename T>
class Graph
{
    private:
        T *vertices;
        SinglyLinkedListUnordered<long long> *adjacencyLists;
        
    public:
        Graph(long long v);
        ~Graph();

        insertVertice(long long index, T item);
        insertEdge(long long v1, long long v2);

};

#endif