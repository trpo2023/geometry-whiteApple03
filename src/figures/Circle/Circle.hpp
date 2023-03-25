#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <libGeometry/geometry.hpp>

class Circle : public Figure {
public:
    Circle(std::string figure_description, std::string figure_name);
    bool check_intersection(Figure& another_figure) override;

    int get_some_infomation() override
    {
        return radius;
    }

    double get_radius()
    {
        return radius;
    }

private:
    double calc_radius(std::string figure_description);
    double calc_square(double radius)
    {
        return M_PI * pow(radius, 2);
    }
    double calc_perimeter(double radius)
    {
        return 2 * M_PI * radius;
    }
    double radius;
};