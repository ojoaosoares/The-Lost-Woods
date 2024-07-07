#include "graph.hpp"

template <typename T, typename Weight>
Graph<T, Weight>::Graph(long long v) {
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
    vertices[index] = item;
}


template <typename T, typename Weight>
void Graph<T, Weight>::insertEdge(long long v1, long long v2, Weight w) {
    std::pair<long long, Weight> newEdge(v1, w);
    adjacencyLists[v1].insertEnd(newEdge);
}


template <typename T, typename Weight>
bool Graph<T, Weight>::isAdjacent(long long v1, long long v2, Weight W) {
    std::pair<long long, Weight> targetEdge(v1, w);
    return adjacencyLists[v1].search(targetEdge) != -1;
}
