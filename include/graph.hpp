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
        Graph(const ll &v);
        ~Graph();

        void insertVertice(const ll &index, const Vert &item);
        Vert getVertice(const ll &index) const;
        SinglyLinkedListUnordered<Tuple<ll, Weight>>* getNeighboors(const ll &v);
        void insertEdge(const ll &v1, const ll &v2, const Weight &w);
};

template <typename Vert, typename Weight>
class Graph_Ad_Matrix
{
    private:
    
        ll vertices_number;
        Vert *vertices;
        Weight **adjacencyMatrix;
        
        
    public:
        Graph_Ad_Matrix(const ll &v);
        ~Graph_Ad_Matrix();

        void insertVertice(const ll &index, const Vert &item);
        Vert getVertice(const ll &index) const;
        Weight* getNeighboors(const ll &v);
        void insertEdge(const ll &v1, const ll &v2, const Weight &W);
};

#endif