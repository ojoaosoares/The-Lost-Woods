#include "graph.hpp"

template <typename Vert, typename Weight>
Graph<Vert, Weight>::Graph(long long v) : vertices_number(v), vertices(new Vert[v]), adjacencyLists(new SinglyLinkedListUnordered<Tuple<long long, Weight>>[v]) { }

template <typename Vert, typename Weight>
Graph<Vert, Weight>::~Graph() {
    delete[] vertices; delete[] adjacencyLists;
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::insertVertice(long long index, Vert item) {
    if(index < 0 || index >= vertices_number)
        throw "Invalid Index";
    vertices[index] = item;
}

template <typename Vert, typename Weight>
Vert Graph<Vert, Weight>::getVertice(long long index) {
    return (vertices[index]);
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::removeVertice(long long index) {
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

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::insertEdge(long long v1, long long v2, Weight w) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";
    
    Tuple<long long, Weight> newEdge(v2, w);
    adjacencyLists[v1].insertEnd(newEdge);
}

template <typename Vert, typename Weight>
SinglyLinkedListUnordered<Tuple<long long, Weight>>* Graph<Vert, Weight>::getNeighboors(long long v) {

    if(v < 0 || v >= vertices_number)
        throw "Invalid Index";

    return &adjacencyLists[v];
}

template <typename Vert, typename Weight>
bool Graph<Vert, Weight>::isAdjacent(long long v1, long long v2) {
    
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";

    SinglyLinkedListUnordered<Tuple<long long, Weight>> *neighboors = getNeighboors(v1);

    long long index = 0;
    for (auto it = neighboors->begin(); it != neighboors->end(); it++)
    {
        if ((*it).first == v2)
            return index;

        index++;
    }
    
    return -1;
    
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::removeEdge(long long v1, long long v2) {
    
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";

    SinglyLinkedListUnordered<Tuple<long long, Weight>> *neighboors = getNeighboors(v1);

    long long index = 0;
    for (auto it = neighboors->begin(); it != neighboors->end(); it++)
    {
        if ((*it).first == v2)
            neighboors->removeIndex(index);

        index++;
    }
    
    throw "Element doesn't exist";
    
}

template class Graph<Tuple<double, double>, double>;
