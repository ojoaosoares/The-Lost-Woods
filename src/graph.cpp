#include "graph.hpp"

template <typename T>
Graph<T>::Graph(long long v) {
    vertices = new T[v];
    adjacencyLists = new SinglyLinkedListUnordered[v];
}

template <typename T>
Graph<T>::~Graph() {
    delete[] vertices;
    delete[] adjacencyLists;
}

template <typename T>
void Graph<T>::insertVertice(long long index, T item) {
    vertices[index] = item;
}

