#include "../figures/all.hpp"
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

Figure* get_figure_obj(std::string figure_description)
{
    std::string figure_name = get_figure_name(figure_description);
    static Circle error{figure_description, "error"};
    if (figure_name == "circle") {
        static Circle circle{figure_description, "circle"};
        return &circle;
    } else if (figure_name == "triangle") {
        static Triangle triangle{figure_description, figure_name};
        return &triangle;
    } else if (figure_name == "polygon") {
        static Polygon polygon{figure_description, figure_name};
        return &polygon;
    }
    std::cout << "error: " << figure_name << std::endl;
    return &error;
}