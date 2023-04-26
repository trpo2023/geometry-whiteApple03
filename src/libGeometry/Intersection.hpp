#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP
#include <math.h>
#include <vector>

class Intersection {
public:
    bool polygon_with_circle(
            std::vector<std::vector<double>> first_coord,
            std::vector<std::vector<double>> second_coord,
            double radius);
    bool polygon_with_polygon(
            std::vector<std::vector<double>> first_coord,
            std::vector<std::vector<double>> second_coord);
};
#endif
