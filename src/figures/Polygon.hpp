#include "../Figure/Figure.hpp"
#include <math.h>
#include <string>
#include <vector>
class Polygon : public Figure {
private:
    double get_vector_multi(double ax, double ay, double bx, double by)
    {
        return ax * by - bx * ay;
    }
    double calc_perimeter(std::vector<std::vector<double>> points)
    {
        double res = 0;
        for (unsigned int i = 0; i < points.size() - 1; i++) {
            res += get_segment_length(points[i], points[i + 1]);
        }
        return res;
    }

    double calc_square(std::vector<std::vector<double>> points)
    {
        unsigned int n = points.size();
        double res = points[0][0] * (points[1][1] - points[n - 2][1]);

        for (unsigned int i = 1; i < n - 1; i++) {
            res += points[i][0] * (points[i + 1][1] - points[i - 1][1]);
        }
        return abs(res / 2);
    }

public:
    bool check_intersection(Figure* another_figure) 
    {
        std::vector<std::vector<double>> first_coord = get_points();
        std::vector<std::vector<double>> second_coord = another_figure->get_points();

        double* vs = new double[4];
        for (unsigned int i = 0; i < first_coord.size() - 1; i++) {
            double x1 = first_coord[i][0], y1 = first_coord[i][1], x2 = first_coord[i + 1][0],
                   y2 = first_coord[i + 1][1];
            // std::cout << "!!!!!!!!!!!!!!!!!first otrezok!!!!!!!!!!!!!!!\n";
            // std::cout << "first point: " << x1 << ' ' << y1
            //           << "\nsecond point: " << x2 << ' ' << y2 << std::endl;

            for (unsigned int k = 0; k < second_coord.size() - 1; k++) {
                double x3 = second_coord[k][0], y3 = second_coord[k][1],
                       x4 = second_coord[k + 1][0], y4 = second_coord[k + 1][1];
                // std::cout << "first point2: " << x3 << ' ' << y3
                //           << "\nsecond point2: " << x4 << ' ' << y4 <<
                //           std::endl;

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
        return false; //-1  1 2 2.52 2 1 -1 3
    }
    Polygon(std::string figure_description, std::string figure_name)
        : Figure(figure_description, figure_name)
    {
        perimeter = calc_perimeter(points);
        square = calc_square(points);
    }
};
