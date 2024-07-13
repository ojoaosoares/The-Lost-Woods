#include "comparator.hpp"

bool Comp_Lost_Woods::operator() (const Tuple<Tuple<ll, ll>, double>& v1, const Tuple<Tuple<ll, ll>, double>& v2) const {
    return (v1.second < v2.second);
}

Comp_A_Star::Comp_A_Star(ll max, double *dist) : max(max), distances(new double[max]) {
    for (ll i = 0; i < max; i++)
        distances[i] = dist[i];
}

Comp_A_Star::~Comp_A_Star() {
    delete[] distances;
} 

bool Comp_A_Star::operator() (const Tuple<Tuple<ll, ll>, double>& v1, const Tuple<Tuple<ll, ll>, double>& v2) const {

}