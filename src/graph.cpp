#include "graph.hpp"

template <typename Vert>
Graph_Ad_List<Vert>::Graph_Ad_List(const ll &v) : verticesNumber(0), maxVertices(v), vertices(new Vert[v]), adjacencyLists(new SinglyLinkedListUnordered<Tuple<ll, double>>[v]) { }

template <typename Vert>
Graph_Ad_List<Vert>::~Graph_Ad_List() {
    delete[] vertices; delete[] adjacencyLists;   
}

template <typename Vert>
void Graph_Ad_List<Vert>::insertVertice(const Vert &item) {
    // Input: (Vert) the vertice to be added
    // Complexity: O(1)
    if(verticesNumber >= maxVertices)
        throw std::out_of_range("The number of vertices reached its limit");
    vertices[verticesNumber++] = item;
}

template <typename Vert>
ll Graph_Ad_List<Vert>::verticeExist(const Vert& item) const {
    // Input: (Vert) the vertice to be added
    // Complexity: O(verticesNumber)
    // Output: (int) the index of the vertice if it exists, else -1
    for (ll i = 0; i < verticesNumber; i++)
        if (vertices[i] == item)
            return i;

    return -1;
}

template <typename Vert>
Vert Graph_Ad_List<Vert>::getVertice(const ll &index) const {
    // Input: (int) the indice of the vertice
    // Complexity: O(1)
    // Output: (Vert) the vertice
    if(index < 0 || index >= verticesNumber)
        throw std::out_of_range("Invalid Index");

    return (vertices[index]);
}

template <typename Vert>
ll Graph_Ad_List<Vert>::getVerticesNumber() const {
    // Complexity: O(1)
    // Output: the vertices number
    return verticesNumber;
}

template <typename Vert>
void Graph_Ad_List<Vert>::insertEdge(const ll &v1, const ll &v2, const double &w) {
    // Input: (int) v1, (int) v2 (double) w, the ordered pair of vertices and the weight of the edge that conects them
    // Complexity: O(1)
    
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");
    
    Tuple<ll, double> newEdge(v2, w);
    adjacencyLists[v1].insertEnd(newEdge);
}

template <typename Vert>
SinglyLinkedListUnordered<Tuple<ll, double>>* Graph_Ad_List<Vert>::getNeighboors(const ll &v) const {
    // Input: (int) v the index of the vertice that you want it neighboors 
    // Complexity: O(1)
    // Output: A singly list that contains the vertices that are adjacent to v

    if(v < 0 || v >= verticesNumber)
        throw std::out_of_range("Invalid Index");

    return &adjacencyLists[v];
}

template <typename Vert>
bool Graph_Ad_List<Vert>::edgeExist(const ll &v1, const ll &v2) const {
    // Input: (int) v1, (int) v2 the ordered pair of vertices that you wanna know if an edge exist
    // Complexity: O(verticesNumber)
    // Output: (bool) true if exists false if it doenst
    
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
    // Input: (int) v1, (int) v2 the ordered pair of vertices that you wanna know if a portal exist
    // Complexity: O(verticesNumber)
    // Output: (bool) true if exists false if it doenst
    
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
    // Complexity: O(maxVertices)
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
    // Complexity: O(maxVertices)
    delete[] vertices;
    
    for (ll i = 0; i < maxVertices; i++)
        delete[] adjacencyMatriz[i];

    delete[] adjacencyMatriz;
}

template <typename Vert>
void Graph_Ad_Matriz<Vert>::insertVertice(const Vert &item) {
    // Input: (Vert) the vertice to be added
    // Complexity: O(1)
    if(verticesNumber >= maxVertices)
        throw std::out_of_range("The number of vertices reached its limit");
    vertices[verticesNumber++] = item;
}

template <typename Vert>
ll Graph_Ad_Matriz<Vert>::verticeExist(const Vert& item) const {
    // Input: (Vert) the vertice to be added
    // Complexity: O(verticesNumber)
    // Output: (int) the index of the vertice if it exists, else -1
    for (ll i = 0; i < verticesNumber; i++)
        if (vertices[i] == item)
            return i;

    return -1;
}

template <typename Vert>
Vert Graph_Ad_Matriz<Vert>::getVertice(const ll &index) const {
    // Input: (int) the indice of the vertice
    // Complexity: O(1)
    // Output: (Vert) the vertice
    if(index < 0 || index >= verticesNumber)
        throw std::out_of_range("Invalid Index");
        
    return (vertices[index]);
}

template <typename Vert>
Tuple<double, bool>* Graph_Ad_Matriz<Vert>::getNeighboors(const ll &v) {
    // Input: (int) v the index of the vertice that you want it neighboors 
    // Complexity: O(1)
    // Output: A tuple vector that contains the vertices that are adjacent to v
    if(v < 0 || v >= verticesNumber)
        throw std::out_of_range("Invalid Index");
    
    return &adjacencyMatriz[v][0];
}

template <typename Vert>
ll Graph_Ad_Matriz<Vert>::getVerticesNumber() const {
    // Complexity: O(1)
    // Output: the vertices number
    return verticesNumber;
}

template <typename Vert>
void Graph_Ad_Matriz<Vert>::insertEdge(const ll &v1, const ll &v2, const double &w) {
    // Input: (int) v1, (int) v2 (double) w, the ordered pair of vertices and the weight of the edge that conects them
    // Complexity: O(1)
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");
         
    adjacencyMatriz[v1][v2].first = w;
}

template <typename Vert>
void Graph_Ad_Matriz<Vert>::insertPortal(const ll &v1, const ll &v2) {
    // Input: (int) v1, (int) v2 (double) w, the ordered pair of vertices that will contains a portal
    // Complexity: O(1)
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");
         
    adjacencyMatriz[v1][v2].second = true;
}

template <typename Vert>
bool Graph_Ad_Matriz<Vert>::edgeExist(const ll &v1, const ll &v2) const {
    // Input: (int) v1, (int) v2 the ordered pair of vertices that you wanna know if an edge exist
    // Complexity: O(1)
    // Output: (bool) true if exists false if it doenst
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");    

    return adjacencyMatriz[v1][v2].first > 0;
}

template <typename Vert>
bool Graph_Ad_Matriz<Vert>::portalExist(const ll &v1, const ll &v2) const {
    // Input: (int) v1, (int) v2 the ordered pair of vertices that you wanna know if a portal exist
    // Complexity: O(1)
    // Output: (bool) true if exists false if it doenst
    if(v1 < 0 || v1 >= verticesNumber || v2 < 0 || v2 >= verticesNumber)
        throw std::out_of_range("Invalid Index");    

    return adjacencyMatriz[v1][v2].second == true;
}

template class Graph_Ad_Matriz<Tuple<double, double>>;