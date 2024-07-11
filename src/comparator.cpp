#include "comparator.hpp"

bool Comp_Lost_Woods::operator() (const double& v1, const double& v2) const {
    return (v1 < v2);
}
