#include <fstream>
#include <math.h>
#include <string>
#include <vector>

#include <libGeometry/geometry.hpp>

class Triangle : public Figure {
public:
    bool check_intersection(Figure& another_figure);
    Triangle(std::string figure_description, std::string figure_name)
        : Figure(figure_description, figure_name)
    {
        if (name == "error") {
            return;
        }
        if (points.size() != 4) {
            name = "error";
            std::ofstream output("output", std::ios::app);
            if (output.is_open()) {
                output << figure_description << "\ntriangle have only 4 points\n";
            }
            return;
        }
        if (points[0][0] != points[points.size() - 1][0]
            or points[0][1] != points[points.size() - 1][1]) {
            name = "error";
            std::ofstream output("output", std::ios::app);
            if (output.is_open()) {
                output << figure_description << "\nthe first and last points must match\n";
            }
        }
        a = get_segment_length(points[0], points[1]);
        b = get_segment_length(points[1], points[2]);
        c = get_segment_length(points[2], points[3]);

        perimeter = calc_perimeter(a, b, c);
        square = calc_square(perimeter);
    }

private:
    double get_vector_multi(double ax, double ay, double bx, double by)
    {
        return ax * by - bx * ay;
    }
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