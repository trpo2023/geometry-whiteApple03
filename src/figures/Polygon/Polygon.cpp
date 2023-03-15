#include "./Polygon.hpp"
#include "../../intersections/Intersection.hpp"
static Intersection intersection;

double Polygon::calc_perimeter(std::vector<std::vector<double>> points)
{
    double res = 0;
    for (unsigned int i = 0; i < points.size() - 1; i++) {
        res += get_segment_length(points[i], points[i + 1]);
    }
    return res;
}

double Polygon::calc_square(std::vector<std::vector<double>> points)
{
    unsigned int n = points.size();
    double res = points[0][0] * (points[1][1] - points[n - 2][1]);

    for (unsigned int i = 1; i < n - 1; i++) {
        res += points[i][0] * (points[i + 1][1] - points[i - 1][1]);
    }
    return abs(res / 2);
}

bool Polygon::check_intersection(Figure& another_figure)
{
    std::vector<std::vector<double>> first_coord = get_points();
    std::vector<std::vector<double>> second_coord = another_figure.get_points();
    std::string another_name = another_figure.get_name();
    if ((another_name == "triangle" or another_name == "polygon")
        and intersection.polygon_with_polygon(first_coord, second_coord)) {
        return true;
    } else if (
            another_name == "circle"
            and intersection.polygon_with_circle(
                    first_coord, second_coord, another_figure.get_some_infomation())) {
        return true;
    }

    return false;
}