#include "../Figure/Figure.hpp"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

class Circle : public Figure {
public:
    Circle(std::string figure_description, std::string figure_name) : Figure(figure_description, figure_name)
    {
        radius = calc_radius(figure_description);
        perimeter = calc_perimeter(radius);
        square = calc_square(radius);
    }
    int get_some_infomation() override
    {
        return radius;
    }

    bool check_intersection(Figure& another_figure) override
    {
        if (another_figure.get_name() == "circle") {
            std::vector<std::vector<double>> center = another_figure.get_points();
            int rad = another_figure.get_some_infomation();
            if (rad + this->radius >= get_segment_length(center[0], this->get_points()[0])) {
                return true;
            }
        } else if (another_figure.get_name() == "polygon") {
					if (check_intersection_with_circle(another_figure.get_points(), this->points, this->radius)) {
						return true;
					}
        }
        return false;
    }
    double get_radius()
    {
        return radius;
    }

private:
    bool pan_duan(std::vector<double> p1, std::vector<double> p2, double r, std::vector<double> center);
    bool check_intersection_with_circle(std::vector<std::vector<double>> first_coord, std::vector<std::vector<double>> second_coord, double radius);
    double calc_radius(std::string figure_description)
    {
        int i = figure_description.rfind(')');
        if (i == -1) {
        }
        std::string radius = "";
        for (; i >= 0; i--) {
            while ((figure_description[i] >= '0' and figure_description[i] <= '9') or figure_description[i] == '-' or figure_description[i] == '.') {
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