#include "graph.hpp"

template <typename Vert>
Graph_Ad_List<Vert>::Graph_Ad_List(const ll &v) : verticesNumber(0), maxVertices(v), vertices(new Vert[v]), adjacencyLists(new SinglyLinkedListUnordered<Tuple<ll, double>>[v]) { }

template <typename Vert>
Graph_Ad_List<Vert>::~Graph_Ad_List() {
    delete[] vertices; delete[] adjacencyLists;   
}

template <typename Vert>
void Graph_Ad_List<Vert>::insertVertice(const Vert &item) {
    if(verticesNumber >= maxVertices)
        throw std::out_of_range("The number of vertices reached its limit");
    vertices[verticesNumber++] = item;
}

template <typename Vert>
ll Graph_Ad_List<Vert>::verticeExist(const Vert& item) const {

    for (ll i = 0; i < verticesNumber; i++)
        if (vertices[i] == item)
            return i;

    return -1;
}

template <typename Vert>
Vert Graph_Ad_List<Vert>::getVertice(const ll &index) const {
    if(index < 0 || index >= verticesNumber)
        throw std::out_of_range("Invalid Index");

    return (vertices[index]);
}

template <typename Vert>
ll Graph_Ad_List<Vert>::getVerticesNumber() const {
    return verticesNumber;
}

template <typename Vert>
void Graph_Ad_List<Vert>::insertEdge(const ll &v1, const ll &v2, const double &w) {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");
    
    Tuple<ll, double> newEdge(v2, w);
    adjacencyLists[v1].insertEnd(newEdge);
}

template <typename Vert>
SinglyLinkedListUnordered<Tuple<ll, double>>* Graph_Ad_List<Vert>::getNeighboors(const ll &v) const {

    if(v < 0 || v >= verticesNumber)
        throw std::out_of_range("Invalid Index");

    return &adjacencyLists[v];
}

template <typename Vert>
bool Graph_Ad_List<Vert>::edgeExist(const ll &v1, const ll &v2) const {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");

    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh = &adjacencyLists[v1];

    for (auto edge = neigh->begin(); edge != neigh->end(); edge++)
        if (edge->first == v2 && edge->second > 0)
            return true;

    return false;
}


template <typename Vert>
bool Graph_Ad_List<Vert>::portalExist(const ll &v1, const ll &v2) const {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");

    SinglyLinkedListUnordered<Tuple<ll, double>> *neigh = &adjacencyLists[v1];

    for (auto edge = neigh->begin(); edge != neigh->end(); edge++)
        if (edge->first == v2 && edge->second == 0)
            return true;

    return false;
}

template class Graph_Ad_List<Tuple<double, double>>;


// Graph with adjacency matriz

template <typename Vert>
Graph_Ad_Matriz<Vert>::Graph_Ad_Matriz(const ll &v) : verticesNumber(0), maxVertices(v), vertices(new Vert[v]), adjacencyMatriz(new Tuple<double, bool>*[v])  {
    for (ll i = 0; i < maxVertices; i++)
        adjacencyMatriz[i] = new Tuple<double, bool>[maxVertices];


    for (ll i = 0; i < maxVertices; i++)
        for (ll j = 0; j < maxVertices; j++)
        {
            adjacencyMatriz[i][j].first = -1;
            adjacencyMatriz[i][j].second = false;
        }
}

template <typename Vert>
Graph_Ad_Matriz<Vert>::~Graph_Ad_Matriz() {
    delete[] vertices;
    
    for (ll i = 0; i < maxVertices; i++)
        delete[] adjacencyMatriz[i];

    delete[] adjacencyMatriz;
}

template <typename Vert>
void Graph_Ad_Matriz<Vert>::insertVertice(const Vert &item) {
    if(verticesNumber >= maxVertices)
        throw std::out_of_range("The number of vertices reached its limit");
    vertices[verticesNumber++] = item;
}

template <typename Vert>
ll Graph_Ad_Matriz<Vert>::verticeExist(const Vert& item) const {
    
    for (ll i = 0; i < verticesNumber; i++)
        if (vertices[i] == item)
            return i;

    return -1;
}

template <typename Vert>
Vert Graph_Ad_Matriz<Vert>::getVertice(const ll &index) const {
    if(index < 0 || index >= verticesNumber)
        throw std::out_of_range("Invalid Index");
        
    return (vertices[index]);
}

template <typename Vert>
Tuple<double, bool>* Graph_Ad_Matriz<Vert>::getNeighboors(const ll &v) {
    if(v < 0 || v >= verticesNumber)
        throw std::out_of_range("Invalid Index");
    
    return &adjacencyMatriz[v][0];
}

template <typename Vert>
ll Graph_Ad_Matriz<Vert>::getVerticesNumber() const {
    return verticesNumber;
}

template <typename Vert>
void Graph_Ad_Matriz<Vert>::insertEdge(const ll &v1, const ll &v2, const double &w) {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");
         
    adjacencyMatriz[v1][v2].first = w;
}

template <typename Vert>
void Graph_Ad_Matriz<Vert>::insertPortal(const ll &v1, const ll &v2) {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");
         
    adjacencyMatriz[v1][v2].second = true;
}

template <typename Vert>
bool Graph_Ad_Matriz<Vert>::edgeExist(const ll &v1, const ll &v2) const {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");    

    return adjacencyMatriz[v1][v2].first > 0;
}

template <typename Vert>
bool Graph_Ad_Matriz<Vert>::portalExist(const ll &v1, const ll &v2) const {
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");    

    return adjacencyMatriz[v1][v2].second == true;
}

template class Graph_Ad_Matriz<Tuple<double, double>>;