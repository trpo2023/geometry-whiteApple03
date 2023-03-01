#include <string>
#include "../figures/Circle/Circle.hpp"
#include "../figures/Polygon/Polygon.hpp"
#include "../figures/Triangle.hpp"

std::string get_figure_name(std::string figure_description)
{
    std::string figure_name;
    for (auto symbol = figure_description.begin();
         symbol < figure_description.end() and *symbol != '(';
         symbol++) {
        if ((*symbol) != ' ') {
            figure_name.push_back(tolower(*symbol));
        }
    }
    return figure_name;
}

const Figure* get_figure_obj(std::string figure_description)
{
    std::string figure_name = get_figure_name(figure_description);
    if (figure_name == "circle") {
        return new Circle{figure_description, figure_name};
    } else if (figure_name == "triangle") {
        return new Polygon{figure_description, figure_name};
    } else if (figure_name == "polygon") {
        return new Polygon{figure_description, figure_name};
    }
    std::cout << "error: " << figure_name << std::endl;
    return new Figure{figure_description, "name_error"};
}