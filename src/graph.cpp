#include "graph.hpp"

template <typename T, typename Weight>
Graph<T, Weight>::Graph(long long v) : vertices_number(v) {
    vertices = new T[v];
    adjacencyLists = new SinglyLinkedListUnordered[v];
}

template <typename T, typename Weight>
Graph<T, Weight>::~Graph() {
    delete[] vertices;
    delete[] adjacencyLists;
}

template <typename T, typename Weight>
void Graph<T, Weight>::insertVertice(long long index, T item) {
    if(index < 0 || index >= vertices_number)
        throw "Invalid Index";
    vertices[index] = item;
}


template <typename T, typename Weight>
void Graph<T, Weight>::insertEdge(long long v1, long long v2, Weight w) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number);
        throw "Invalid Index";
    
    std::pair<long long, Weight> newEdge(v1, w);
    adjacencyLists[v1].insertEnd(newEdge);
}


template <typename T, typename Weight>
bool Graph<T, Weight>::isAdjacent(long long v1, long long v2, Weight W) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number);
        throw "Invalid Index";

    std::pair<long long, Weight> targetEdge(v1, w);
    return adjacencyLists[v1].search(targetEdge) != -1;
}


template <typename T, typename Weight>
void Graph<T, Weight>::removeEdge(long long v1, long long v2, Weight W) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number);
        throw "Invalid Index";

    std::pair<long long, Weight> targetEdge(v1, w);
    
    long long index = adjacencyLists[v1].search(targetEdge);

    if (index == -1)
        throw "Element doesn't exist";  

    adjacencyLists[v1].removeIndex(index);
}