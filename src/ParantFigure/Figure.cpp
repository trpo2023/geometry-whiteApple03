#include "./Figure.hpp"

Figure::Figure(std::string figure_description, std::string figure_name)
{
    if (figure_name == "name_error") {
        int left;
        int right;
        get_name_borders(figure_description, &left, &right);
        handling_incorrect_name(figure_description, left, right);
    }
    name = figure_name;
    points = get_points(figure_description);
}

void Figure::get_name_borders(std::string figure_description, int* left_border, int* right_border)
{
    bool left_border_is_found = false;
    for (unsigned int i = 0; i < figure_description.size() - 1; i++) {
        if (left_border_is_found and figure_description[i] != ' ' and (figure_description[i + 1] == ' ' or figure_description[i + 1] == '(')) {
            *right_border = i;
						break;
        }
        if (!left_border_is_found and figure_description[i] != ' ') {
            *left_border = i;
            left_border_is_found = true;
        }
    }
}

void Figure::handling_incorrect_name(std::string figure_description, int left_border, int right_border)
{
    std::cout << figure_description << std::endl;

    for (int i = 0; i < right_border; i++) {
        if (i < left_border) {
            std::cout << ' ';
        } else {
            std::cout << "\033[31m~\033[0m";
        }
    }
    std::cout << "^"
              << "\tIncorrect name: it should be polygon, circle or triangle\n\n";
    exit(1);
}

std::vector<std::vector<double>> Figure::get_points(std::string figure_description)
{
    int i = figure_description.find('(');
    int points_quantity = 0;
    std::vector<std::vector<double>> returned_points(5);
    if (i == -1) {
        std::cout << "error\n";
    }
    int digit_point = 0;
    std::vector<std::string> digit(2);
    for (; figure_description[i] != ')'; i++) {
        if ((long unsigned int)points_quantity > returned_points.size() - 1) {
            returned_points.resize(returned_points.size() + 10);
        }
        while ((figure_description[i] >= '0' and figure_description[i] <= '9') or figure_description[i] == '-' or figure_description[i] == '.') {
            digit[digit_point].push_back(figure_description[i]);

            if ((figure_description[i + 1] < '0' or figure_description[i + 1] > '9') and figure_description[i + 1] != '.') {
                digit_point = (digit_point + 1) % 2;
            }
            i++;
        }
        if (digit[1].size() > 0 and (figure_description[i] == ',' or figure_description[i] == ')')) {
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