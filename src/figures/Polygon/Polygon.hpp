#include "../../ParantFigure/Figure.hpp"
#include <math.h>
#include <string>
#include <vector>
class Polygon : public Figure {
private:
    double calc_perimeter(std::vector<std::vector<double>> points);
    double calc_square(std::vector<std::vector<double>> points);

public:
    bool check_intersection(Figure& another_figure) override;

    Polygon(std::string figure_description, std::string figure_name) : Figure(figure_description, figure_name)
    {
        perimeter = calc_perimeter(points);
        square = calc_square(points);
    }
};
