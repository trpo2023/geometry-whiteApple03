#include "../Figure/Figure.hpp"
#include <math.h>
#include <string>
#include <vector>
class Polygon : public Figure {
private:
    double get_segment_length(
            std::vector<double> first_point, std::vector<double> second_point)
    {
        return sqrt(
                pow(second_point[0] - first_point[0], 2)
                + pow(second_point[1] - first_point[1], 2));
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
        return res / 2;
    }

public:
    Polygon(std::string figure_description, std::string figure_name)
        : Figure(figure_description, figure_name)
    {
        perimeter = calc_perimeter(points);
        square = calc_square(points);
    }
};
