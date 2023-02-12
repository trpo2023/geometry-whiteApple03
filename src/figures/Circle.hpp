#pragma once
#include "../Figure/Figure.hpp"
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>

#include <map>

class Circle : public Figure {
public:
    Circle(std::string figure_description, std::string figure_name)
        : Figure(figure_description, figure_name)
    {
        radius = calc_radius(figure_description);
        perimeter = calc_perimeter(radius);
        square = calc_square(radius);
    }

    double get_radius()
    {
        return radius;
    }

private:
    double calc_radius(std::string figure_description)
    {
        int i = figure_description.rfind(')');
        if (i == -1) {
        }
        std::string radius = "";
        for (; i >= 0; i--) {
            while ((figure_description[i] > '0' and figure_description[i] < '9')
                   or figure_description[i] == '-'
                   or figure_description[i] == '.') {
                radius.push_back(figure_description[i]);
                i--;
            }
            if (radius.size() > 0 and figure_description[i] == ',') {
                reverse(radius.begin(), radius.end());
                std::cout << "std radius" << radius << std::endl;
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