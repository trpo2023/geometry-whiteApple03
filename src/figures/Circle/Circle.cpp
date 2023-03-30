#include <Circle.hpp>
static Intersection intersection;

Circle::Circle(std::string figure_description, std::string figure_name)
    : Figure(figure_description, figure_name)
{
    if (name == "error") {
        return;
    }
    radius = calc_radius(figure_description);
    if (radius <= 0) {
        name = "error";
        std::cout << figure_description << "\nradius > 0\n";
        return;
    }
    perimeter = calc_perimeter(radius);
    square = calc_square(radius);
}

bool Circle::check_intersection(Figure& another_figure)
{
    if (another_figure.get_name() == "circle") {
        std::vector<std::vector<double>> center = another_figure.get_points();
        int rad = another_figure.get_some_infomation();
        if (rad + this->radius >= get_segment_length(center[0], this->get_points()[0])) {
            return true;
        }
    } else if (another_figure.get_name() == "polygon" or another_figure.get_name() == "triangle") {
        if (intersection.polygon_with_circle(
                    another_figure.get_points(), this->points, this->radius)) {
            return true;
        }
    }
    return false;
}

double Circle::calc_radius(std::string figure_description)
{
    int i = figure_description.rfind(')');
    if (i == -1) {
    }
    std::string radius = "";
    for (; i >= 0; i--) {
        while ((figure_description[i] >= '0' and figure_description[i] <= '9')
               or figure_description[i] == '-' or figure_description[i] == '.') {
            radius.push_back(figure_description[i]);
            i--;
        }
        if (radius.size() > 0 and figure_description[i] == ',') {
            reverse(radius.begin(), radius.end());
            return stod(radius);
        }
    }
    std::cout << "error: did't find the radius\n";
    return -1;
}