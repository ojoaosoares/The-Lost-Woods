#include "comparator.hpp"

bool Comp_Dijkstra::operator() (const double& v1, const double& v2) const {
    return v1 < v2;
}


bool Comp_A_Star::operator() (const Tuple<double, double>& v1, const Tuple<double, double>& v2) const {
    return v1.second + v1.first < v2.second + v2.first;
}