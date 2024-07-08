#include "graph.hpp"

template <typename T, typename Weight>
Graph<T, Weight>::Graph(long long v) : vertices_number(v) {
    vertices = new T[v];
    adjacencyLists = new SinglyLinkedListUnordered<std::pair<long long, Weight>>[v];
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
T Graph<T, Weight>::getVertice(long long index) {
    return (vertices[index]);
}

template <typename T, typename Weight>
void Graph<T, Weight>::removeVertice(long long index) {
    if(index < 0 || index >= vertices_number)
        throw "Invalid Index";
    
    adjacencyLists[index].clear();

    for (long long i = 0; i < vertices_number; i++)
    {
        try
        {
            removeEdge(i, index);
        }
        catch(const std::exception& e)
        {

        }
        
    }
}

template <typename T, typename Weight>
void Graph<T, Weight>::insertEdge(long long v1, long long v2, Weight w) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";
    
    std::pair<long long, Weight> newEdge(v2, w);
    adjacencyLists[v1].insertEnd(newEdge);
}

template <typename T, typename Weight>
SinglyLinkedListUnordered<std::pair<long long, Weight>>* Graph<T, Weight>::getNeighboors(long long v) {

    if(v < 0 || v >= vertices_number)
        throw "Invalid Index";

    return &adjacencyLists[v];
}

template <typename T, typename Weight>
bool Graph<T, Weight>::isAdjacent(long long v1, long long v2) {
    
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";

    SinglyLinkedListUnordered<std::pair<long long, Weight>> *neighboors = getNeighboors(v1);

    long long index = 0;
    for (auto it = neighboors->begin(); it != neighboors->end(); it++)
    {
        if ((*it).first == v2)
            return index;

        index++;
    }
    
    return -1;
    
}

template <typename T, typename Weight>
void Graph<T, Weight>::removeEdge(long long v1, long long v2) {
    
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";

    SinglyLinkedListUnordered<std::pair<long long, Weight>> *neighboors = getNeighboors(v1);

    long long index = 0;
    for (auto it = neighboors->begin(); it != neighboors->end(); it++)
    {
        if ((*it).first == v2)
            neighboors->removeIndex(index);

        index++;
    }
    
    throw "Element doesn't exist";
    
}


template class Graph<std::pair<long long, long long>, long long>;
template class Graph<std::pair<long long, long long>, int>;
template class Graph<std::pair<long long, long long>, double>;

template class Graph<std::pair<double, double>, long long>;
template class Graph<std::pair<double, double>, int>;
template class Graph<std::pair<double, double>, double>;
