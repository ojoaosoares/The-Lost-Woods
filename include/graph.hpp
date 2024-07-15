#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "singlylinkedlistunordered.hpp"
#include "tuple.hpp"

typedef long long ll;

template <typename Vert>
class Graph_Ad_List
{
    private:
    
        ll verticesNumber, maxVertices;
        Vert *vertices;
        SinglyLinkedListUnordered<Tuple<ll, double>> *adjacencyLists;
        
        
    public:
        Graph_Ad_List(const ll &v);
        ~Graph_Ad_List();

        void insertVertice(const Vert &item);
        ll verticeExist(const Vert& item) const;
        Vert getVertice(const ll &index) const;
        ll getVerticesNumber() const;
        SinglyLinkedListUnordered<Tuple<ll, double>>* getNeighboors(const ll &v) const;
        void insertEdge(const ll &v1, const ll &v2, const double &w);
        bool edgeExist(const ll &v1, const ll &v2) const;
};

template <typename Vert>
class Graph_Ad_Matrix
{
    private:
    
        ll verticesNumber, maxVertices;
        Vert *vertices;
        double **adjacencyMatrix;
        
        
    public:
        Graph_Ad_Matrix(const ll &v);
        ~Graph_Ad_Matrix();

        void insertVertice(const Vert &item);
        ll verticeExist(const Vert& item) const;
        Vert getVertice(const ll &index) const;
        ll getVerticesNumber() const;
        double* getNeighboors(const ll &v);
        void insertEdge(const ll &v1, const ll &v2, const double &W);
};

#endif