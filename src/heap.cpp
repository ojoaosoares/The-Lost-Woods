#include "heap.hpp"

template <typename Key, typename Value, class Comparator, class Hash>
Heap<Key, Value, Comparator, Hash>::Heap(ll maxsize, Comparator comp, Hash hash) : size(0), maxSize(maxsize), data(new Tuple<Key, Value>[maxsize]), indexes(new ll[maxsize]), comp(comp), hash(hash) {
    for (ll i = 0; i < maxsize; i++) indexes[i] = -1;
}

template <typename Key, typename Value, class Comparator, class Hash>
Heap<Key, Value, Comparator, Hash>::~Heap() {
    delete[] data; delete[] indexes;
}

template <typename Key, typename Value, class Comparator, class Hash>
ll Heap<Key, Value, Comparator, Hash>::getFather(ll i){
    return (i-1)/2;
}

template <typename Key, typename Value, class Comparator, class Hash>
ll Heap<Key, Value, Comparator, Hash>::getLeftChild(ll i){
    return 2 * i + 1;
}

template <typename Key, typename Value, class Comparator, class Hash>
ll Heap<Key, Value, Comparator, Hash>::getRightChild(ll i){
    return 2 * i + 2;
}

template <typename Key, typename Value, class Comparator, class Hash>
bool Heap<Key, Value, Comparator, Hash>::empty()
{
    return size == 0;
}

template <typename Key, typename Value, class Comparator, class Hash>
Tuple<Key, Value>* Heap<Key, Value, Comparator, Hash>::contains(Key key)
{
    ll index = indexes[hash(key)];

    if (index == -1) return nullptr;

    return &data[index];
}


template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::insert(Key key, Value value) {

    if (size == maxSize)
        throw "Heap is full";

    data[size].first = key;
    data[size].second = value;

    indexes[hash(key)] = size;

    heapifyDown(size);

    size++;
}

template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::update(Key key, Value value) {

    Tuple<Key, Value>* item = contains(key);
    if (item == nullptr)
        throw "Index doesn't exist";

    item->second = value;
    if (comp(value, item->second))    
        heapifyDown(indexes[hash(key)]);
    

    else
        heapifyUp(indexes[hash(key)]);
    
    
    
}

template <typename Key, typename Value, class Comparator, class Hash>
Tuple<Key, Value> Heap<Key, Value, Comparator, Hash>::remove()
{
    if (empty())
        throw "Heap is empty";

    Tuple<Key, Value> temp = data[0];
    indexes[hash(data[0].first)] = -1; size--;

    if(!empty())
    {
        data[0] = data[size];
        indexes[hash(data[0].first)] = 0;

        heapifyUp(0);
    }

    return temp;
}


template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::heapifyDown(ll pos)
{
    ll current = pos, 
    father = getFather(current);

    while (current > 0 && comp(data[current].second, data[father].second))
    {
        Tuple<Key, Value> temp = data[current];
        data[current] = data[father];
        data[father] = temp;

        ll temp_index = indexes[hash(data[current].first)];
        indexes[hash(data[current].first)] = indexes[hash(data[father].first)];
        indexes[hash(data[father].first)] = temp_index;

        current = father;
        father = getFather(current);
    }   
}

template <typename Key, typename Value, class Comparator, class Hash>
void Heap<Key, Value, Comparator, Hash>::heapifyUp(ll pos)
{
    ll current = pos, smallest_child,
    left = getLeftChild(current),
    right = getRightChild(current);

    if (left >= size)
        return;

    else if (right >= size)
        smallest_child = left;

    else smallest_child = comp(data[left].second, data[right].second) ? left : right;

    while (comp(data[smallest_child].second, data[current].second))
    {
        Tuple<Key, Value> temp = data[current];
        data[current] = data[smallest_child];
        data[smallest_child] = temp;

        ll temp_index = indexes[hash(data[current].first)];
        indexes[hash(data[current].first)] = indexes[hash(data[smallest_child].first)];
        indexes[hash(data[smallest_child].first)] = temp_index;

        current = smallest_child;
        left = getLeftChild(current);
        right = getRightChild(current);

        if (left >= size)
            return;

        else if (right >= size)
            smallest_child = left;

        else smallest_child = comp(data[left].second, data[right].second) ? left : right;
    }

}

Hash_Custom::Hash_Custom(ll vertice, ll portals) : vert(vertice), portals(portals) {}

ll Hash_Custom::operator() (const Tuple<ll, ll>& key) const {
    return (portals * key.first + key.second);
}

bool Comp_Dijkstra::operator() (const double& v1, const double& v2) const {
    return v1 < v2;
}

bool Comp_A_Star::operator() (const Tuple<double, double>& v1, const Tuple<double, double>& v2) const {
    return v1.second + v1.first < v2.second + v2.first;
}

template class Heap<Tuple<ll, ll>, double, Comp_Dijkstra, Hash_Custom>;
template class Heap<Tuple<ll, ll>, Tuple<double, double>, Comp_A_Star, Hash_Custom>;