#include "./Figure.hpp"

std::string Figure::get_config(std::string figure_name)
{
    std::string config = "";
    if (figure_name == "circle") {
        config = "(dd,d)";
    } else if (figure_name == "triangle") {
        config = "((dd,dd,dd,dd))";
    } else if (figure_name == "polygon") {
        config = "(({dd}))";
    }
    return config;
}

Figure::Figure(std::string figure_description, std::string figure_name)
{
    name_borders cur_name_borders = {0, 0};
    get_name_borders(
            figure_description, cur_name_borders.left_border, cur_name_borders.right_border);

    if (figure_name == "name_error") {
        error_highlighting(
                figure_description, cur_name_borders.left_border, cur_name_borders.right_border);
        std::cout << "\tIncorrect name: it should be polygon, circle or triangle\n\n";
        name = "error";
        return;
    }
    point_name_borders = &cur_name_borders;

    name = figure_name;

    check_correctness_of_data(figure_description, get_config(name));
    if (name == "error") {
        return;
    }
    points = get_points(figure_description, get_config(name));
}

void Figure::get_name_borders(std::string figure_description, int& left_border, int& right_border)
{
    std::string figure_name;
    bool first_char = false;
    for (unsigned int i = 0; i < figure_description.size(); i++) {
        if (first_char and (figure_description[i] == ' ' or figure_description[i] == '(')) {
            right_border = i - 1;
            break;
        }
        if (!first_char and (figure_description[i]) != ' ') {
            left_border = i;
            first_char = true;
        }
        if (first_char and (figure_description[i]) != ' ') {
            figure_name.push_back(tolower(figure_description[i]));
        }
    }
}

void Figure::error_highlighting(std::string figure_description, int left_border, int right_border)
{
    std::cout << figure_description << std::endl;

    for (int i = 0; i < right_border; i++) {
        if (i < left_border) {
            std::cout << ' ';
        } else {
            std::cout << "\033[31m~\033[0m";
        }
    }
    std::cout << "^";
}

std::vector<std::vector<double>>
Figure::get_points(std::string figure_description, std::string config)
{
    int index_config = 1;
    int i = figure_description.find('(');
    int points_quantity = 0;
    std::vector<std::vector<double>> returned_points(5);

    int digit_point = 0;
    std::vector<std::string> digit(2);
    for (; figure_description[i] != ')'; i++) {
        if ((long unsigned int)points_quantity > returned_points.size() - 1) {
            returned_points.resize(returned_points.size() + 10);
        }
        if (figure_description[i] == config[index_config]) {
            index_config++;
        }
        while ((figure_description[i] >= '0' and figure_description[i] <= '9')
               or figure_description[i] == '-' or figure_description[i] == '.') {
            digit[digit_point].push_back(figure_description[i]);

            if ((figure_description[i + 1] < '0' or figure_description[i + 1] > '9')
                and figure_description[i + 1] != '.') {
                digit_point = (digit_point + 1) % 2;
            }
            i++;
        }
        if (digit[1].size() > 0
            and (figure_description[i] == ',' or figure_description[i] == ')')) {
            returned_points[points_quantity].reserve(2);
            returned_points[points_quantity].push_back(stod(digit[0]));
            returned_points[points_quantity].push_back(stod(digit[1]));
            digit[0] = "";
            digit[1] = "";
            digit_point = 0;
            points_quantity++;
        }
        if (figure_description[i] == ')') {
            returned_points.resize(points_quantity);
            break;
        }
    }
    if (digit[0].size() > 0 and digit[1].size() > 0) {
        returned_points[points_quantity].push_back(stod(digit[0]));
        returned_points[points_quantity].push_back(stod(digit[1]));
        points_quantity++;
    }
    returned_points.resize(points_quantity);
    return returned_points;
}