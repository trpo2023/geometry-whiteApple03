#include "../figures/Circle.hpp"
#include <string>

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


Figure get_figure_obj(std::string figure_description)
{
    std::string figure_name = get_figure_name(figure_description);
    Circle error{figure_description, figure_name};
    if (figure_name == "circle") {
        Circle circle{figure_description, "circle"};
        return circle;
    }
		return error;
}