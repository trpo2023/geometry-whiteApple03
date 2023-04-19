#include <string>

#include <Circle.hpp>
#include <Polygon.hpp>
#include <Triangle.hpp>

std::string get_figure_name(std::string figure_description)
{
    std::string figure_name;
    bool first_char = false;
    for (auto symbol = figure_description.begin(); symbol < figure_description.end(); symbol++) {
        if (first_char and (*symbol == ' ' or *symbol == '(')) {
            break;
        }
        if (!first_char and (*symbol) != ' ') {
            first_char = true;
        }
        if (first_char and (*symbol) != ' ') {
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
    return new Figure{figure_description, "name_error"};
}