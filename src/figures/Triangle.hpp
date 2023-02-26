#include "../Figure/Figure.hpp"
#include <math.h>
#include <string>
#include <vector>

class Triangle : public Figure {
public:
    bool check_intersection(Figure& another_figure)
    {
        std::vector<std::vector<double>> first_coord = get_points();
        std::vector<std::vector<double>> second_coord = another_figure.get_points();
        if (another_figure.get_name() == "triangle" or another_figure.get_name() == "polygon") {
            double* vs = new double[4];
            for (unsigned int i = 0; i < first_coord.size() - 1; i++) {
                double x1 = first_coord[i][0], y1 = first_coord[i][1], x2 = first_coord[i + 1][0],
                       y2 = first_coord[i + 1][1];


                for (unsigned int k = 0; k < second_coord.size() - 1; k++) {
                    double x3 = second_coord[k][0], y3 = second_coord[k][1],
                           x4 = second_coord[k + 1][0], y4 = second_coord[k + 1][1];


                    vs[0] = get_vector_multi(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
                    vs[1] = get_vector_multi(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
                    vs[2] = get_vector_multi(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
                    vs[3] = get_vector_multi(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
                    if ((vs[0] * vs[1] <= 0 and vs[2] * vs[3] <= 0)
                        or (((x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3) == 0)
                            or ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3) == 0))) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
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