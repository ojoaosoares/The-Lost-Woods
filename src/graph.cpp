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
    return (vertices[index]);
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::insertEdge(const ll &v1, const ll &v2, const Weight &W) {
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
