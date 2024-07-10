#include "euclidean_distance.hpp"

#include <cmath>

double euclidean_distance(Tuple<double, double> const& p1, Tuple<double, double> const& p2) {
    return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}