
#include <Triangle.hpp>

static Intersection intersection;

bool Triangle::check_intersection(Figure& another_figure)
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