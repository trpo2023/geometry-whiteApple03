#include <libGeometry/geometry.hpp>
#include <math.h>
#include <string>
#include <vector>

class Polygon : public Figure {
public:
    Polygon(std::string figure_description, std::string figure_name)
        : Figure(figure_description, figure_name)
    {
        if (name == "error") {
            return;
        }
        if (points[0][0] != points[points.size() - 1][0]
            or points[0][1] != points[points.size() - 1][1]) {
            name = "error";
            std::cout << figure_description << "\nthe first and last points must match\n";
        }
        perimeter = calc_perimeter(points);
        square = calc_square(points);
    }
    bool check_intersection(Figure& another_figure) override;

private:
    double calc_perimeter(std::vector<std::vector<double>> points);
    double calc_square(std::vector<std::vector<double>> points);
};
