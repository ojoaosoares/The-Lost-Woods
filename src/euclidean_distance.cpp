#include "euclidean_distance.hpp"

#include <cmath>

double euclidean_distance(std::pair<double, double> const& p1, std::pair<double, double> const& p2) {
    return sqrt(pow((p1.first - p2.first), 2) + pow((p1.second - p2.second), 2));
}