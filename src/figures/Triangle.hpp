#include "../Figure/Figure.hpp"
#include <math.h>
#include <string>
#include <vector>

class Triangle : public Figure {
public:
    Triangle(std::string figure_description, std::string figure_name)
        : Figure(figure_description, figure_name)
    {
        a = get_segment_length(points[0], points[1]);
        b = get_segment_length(points[1], points[2]);
        c = get_segment_length(points[2], points[3]);

        perimeter = calc_perimeter(a, b, c);
        square = calc_square(perimeter);
    }

private:

    double calc_square(double perimeter)
    {
        double semi_perimeter = perimeter / 2;
        return sqrt(
                semi_perimeter * (semi_perimeter - a) * (semi_perimeter - b)
                * (semi_perimeter - c));
    }
    double calc_perimeter(double a, double b, double c)
    {
        return a + b + c;
    }
    double a, b, c;
};