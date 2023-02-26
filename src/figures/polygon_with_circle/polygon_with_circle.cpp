#include "../Circle.hpp"
#include "../Polygon.hpp"
#include <math.h>
#include <vector>

double get_segment_length(std::vector<double> first_point, std::vector<double> second_point)
{
    return sqrt(pow(second_point[0] - first_point[0], 2) + pow(second_point[1] - first_point[1], 2));
}

bool Polygon::pan_duan(std::vector<double> p1, std::vector<double> p2, double r, std::vector<double> center)
{
    double a, b, c, dist1, dist2, angle1, angle2;
    dist1 = get_segment_length(p1, center);
    dist2 = get_segment_length(p2, center);
    if ((dist1 <= r and dist2 >= r) or (dist1 >= r and dist2 <= r)) {
        return true;
    }
    if (dist1 < r and dist2 < r) {
        return false;
    }
    if (p1[0] == p2[0])
        a = 1, b = 0, c = -p1[0];
    else if (p1[1] == p2[1])
        a = 0, b = 1, c = -p1[1];
    else {
        a = p1[1] - p2[1];
        b = p2[0] - p1[0];
        c = p1[0] * p2[1] - p1[1] * p2[0];
    }

    dist1 = a * center[0] + b * center[1] + c;
    dist1 *= dist1;
    dist2 = (a * a + b * b) * r * r;
    if (dist1 > dist2)
        return 0;
    angle1 = (center[0] - p1[0]) * (p2[0] - p1[0]) + (center[1] - p1[1]) * (p2[1] - p1[1]);
    angle2 = (center[0] - p2[0]) * (p1[0] - p2[0]) + (center[1] - p2[1]) * (p1[1] - p2[1]);
    if (angle1 > 0 && angle2 > 0)
        return true;

    return false;
}

bool Polygon::check_intersection_with_circle(std::vector<std::vector<double>> first_coord, std::vector<std::vector<double>> second_coord, double radius)
{
    for (unsigned int i = 0; i < first_coord.size() - 1; i++) {
        if (pan_duan(first_coord[i], first_coord[i + 1], radius, second_coord[0])) {
            return true;
        }
    }
    return false;
}

bool Circle::pan_duan(std::vector<double> p1, std::vector<double> p2, double r, std::vector<double> center)
{
    double a, b, c, dist1, dist2, angle1, angle2;
    dist1 = get_segment_length(p1, center);
    dist2 = get_segment_length(p2, center);
    if ((dist1 <= r and dist2 >= r) or (dist1 >= r and dist2 <= r)) {
        return true;
    }
    if (dist1 < r and dist2 < r) {
        return false;
    }
    if (p1[0] == p2[0])
        a = 1, b = 0, c = -p1[0];
    else if (p1[1] == p2[1])
        a = 0, b = 1, c = -p1[1];
    else {
        a = p1[1] - p2[1];
        b = p2[0] - p1[0];
        c = p1[0] * p2[1] - p1[1] * p2[0];
    }

    dist1 = a * center[0] + b * center[1] + c;
    dist1 *= dist1;
    dist2 = (a * a + b * b) * r * r;
    if (dist1 > dist2)
        return 0;
    angle1 = (center[0] - p1[0]) * (p2[0] - p1[0]) + (center[1] - p1[1]) * (p2[1] - p1[1]);
    angle2 = (center[0] - p2[0]) * (p1[0] - p2[0]) + (center[1] - p2[1]) * (p1[1] - p2[1]);
    if (angle1 > 0 && angle2 > 0)
        return true;

    return false;
}

bool Circle::check_intersection_with_circle(std::vector<std::vector<double>> first_coord, std::vector<std::vector<double>> second_coord, double radius)
{
    for (unsigned int i = 0; i < first_coord.size() - 1; i++) {
        if (pan_duan(first_coord[i], first_coord[i + 1], radius, second_coord[0])) {
            return true;
        }
    }
    return false;
}