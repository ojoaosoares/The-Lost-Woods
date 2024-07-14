#include "graph.hpp"

template <typename Vert, typename Weight>
Graph<Vert, Weight>::Graph(const ll &v) : vertices_number(v), vertices(new Vert[v]), adjacencyLists(new SinglyLinkedListUnordered<Tuple<ll, Weight>>[v]) { }

template <typename Vert, typename Weight>
Graph<Vert, Weight>::~Graph() {
    delete[] vertices; delete[] adjacencyLists;   
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::insertVertice(const ll &index, const Vert &item) {
    if(index < 0 || index >= vertices_number)
        throw std::out_of_range("Invalid Index");
    vertices[index] = item;
}

template <typename Vert, typename Weight>
Vert Graph<Vert, Weight>::getVertice(const ll &index) const {
    if(index < 0 || index >= vertices_number)
        throw std::out_of_range("Invalid Index");

    return (vertices[index]);
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::insertEdge(const ll &v1, const ll &v2, const Weight &w) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw std::out_of_range("Invalid Index");
    
    Tuple<ll, Weight> newEdge(v2, w);
    adjacencyLists[v1].insertEnd(newEdge);
}

template <typename Vert, typename Weight>
SinglyLinkedListUnordered<Tuple<ll, Weight>>* Graph<Vert, Weight>::getNeighboors(const ll &v) {

    if(v < 0 || v >= vertices_number)
        throw std::out_of_range("Invalid Index");

    return &adjacencyLists[v];
}

template class Graph<Tuple<double, double>, Tuple<double, ll>>;


// Graph with adjacency matriz

template <typename Vert, typename Weight>
Graph_Ad_Matrix<Vert, Weight>::Graph_Ad_Matrix(const ll &v) : vertices_number(v), vertices(new Vert[v]), adjacencyMatrix(new Weight*[v])  {
    for (ll i = 0; i < vertices_number; i++)
        adjacencyMatrix[i] = new Weight[vertices_number];
}

template <typename Vert, typename Weight>
Graph_Ad_Matrix<Vert, Weight>::~Graph_Ad_Matrix() {
    delete[] vertices;
    
    for (ll i = 0; i < vertices_number; i++)
        delete[] adjacencyMatrix[i];

    delete[] adjacencyMatrix;
}

template <typename Vert, typename Weight>
void Graph_Ad_Matrix<Vert, Weight>::insertVertice(const ll &index, const Vert &item) {
    if(index < 0 || index >= vertices_number)
        throw std::out_of_range("Invalid Index");
    vertices[index] = item;
}

template <typename Vert, typename Weight>
Vert Graph_Ad_Matrix<Vert, Weight>::getVertice(const ll &index) const {
    if(index < 0 || index >= vertices_number)
        throw std::out_of_range("Invalid Index");
        
    return (vertices[index]);
}

template <typename Vert, typename Weight>
Weight* Graph_Ad_Matrix<Vert, Weight>::getNeighboors(const ll &v) {
    if(v < 0 || v >= vertices_number)
        throw std::out_of_range("Invalid Index");
    
    return adjacencyMatrix[v];
}

template <typename Vert, typename Weight>
void Graph_Ad_Matrix<Vert, Weight>::insertEdge(const ll &v1, const ll &v2, const Weight &w) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw std::out_of_range("Invalid Index");
         
    adjacencyMatrix[v1][v2] = w;
}