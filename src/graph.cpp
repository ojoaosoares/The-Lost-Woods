#include "graph.hpp"


template <typename Vert, typename Weight>
Graph<Vert, Weight>::Graph(ll v) : vertices_number(v), vertices(new Vert[v]), adjacencyLists(new SinglyLinkedListUnordered<Tuple<ll, Weight>>[v]) { }

template <typename Vert, typename Weight>
Graph<Vert, Weight>::~Graph() {
    delete[] vertices; delete[] adjacencyLists;
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::insertVertice(ll index, Vert item) {
    if(index < 0 || index >= vertices_number)
        throw "Invalid Index";
    vertices[index] = item;
}

template <typename Vert, typename Weight>
Vert Graph<Vert, Weight>::getVertice(ll index) {
    return (vertices[index]);
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::removeVertice(ll index) {
    if(index < 0 || index >= vertices_number)
        throw "Invalid Index";
    
    adjacencyLists[index].clear();

    for (ll i = 0; i < vertices_number; i++)
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
void Graph<Vert, Weight>::insertEdge(ll v1, ll v2, Weight w) {
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";
    
    Tuple<ll, Weight> newEdge(v2, w);
    adjacencyLists[v1].insertEnd(newEdge);
}

template <typename Vert, typename Weight>
SinglyLinkedListUnordered<Tuple<ll, Weight>>* Graph<Vert, Weight>::getNeighboors(ll v) {

    if(v < 0 || v >= vertices_number)
        throw "Invalid Index";

    return &adjacencyLists[v];
}

template <typename Vert, typename Weight>
bool Graph<Vert, Weight>::isAdjacent(ll v1, ll v2) {
    
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";

    SinglyLinkedListUnordered<Tuple<ll, Weight>> *neighboors = getNeighboors(v1);

    ll index = 0;
    for (auto it = neighboors->begin(); it != neighboors->end(); it++)
    {
        if ((*it).first == v2)
            return index;

        index++;
    }
    
    return -1;
    
}

template <typename Vert, typename Weight>
void Graph<Vert, Weight>::removeEdge(ll v1, ll v2) {
    
    if(v1 < 0 || v1 >= vertices_number || v2 < 0 || v2 >= vertices_number)
        throw "Invalid Index";

    SinglyLinkedListUnordered<Tuple<ll, Weight>> *neighboors = getNeighboors(v1);

    ll index = 0;
    for (auto it = neighboors->begin(); it != neighboors->end(); it++)
    {
        if ((*it).first == v2)
            neighboors->removeIndex(index);

        index++;
    }
    
    throw "Element doesn't exist";
    
}

template class Graph<Tuple<double, double>, Tuple<double, ll>>;
