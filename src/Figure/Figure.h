#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Figure {
public:
    Figure(string figure_description)
    {
        name = get_figure_name(figure_description);
        points = get_points(figure_description);
    }

    vector<vector<double>> get_points()
    {
        return points;
    }
    string get_name()
    {
        return name;
    }
    double get_perimeter()
    {
        return perimeter;
    }

    double get_square()
    {
        return square;
    }

private:
    vector<vector<double>> get_points(string figure_description)
    {
        int i = figure_description.find('(');
        int points_quantity = 0;
        vector<vector<double>> returned_points(5);
        returned_points[0].reserve(3);
        if (i == -1) {
            cout << "error\n";
        }
        int digit_point = 0;
        vector<string> digit(2);
        for (; figure_description[i] != ')'; i++) {
            if ((long unsigned int)points_quantity
                > returned_points.size() - 1) {
                returned_points.resize(returned_points.size() + 10);
            }
            while ((figure_description[i] > '0' and figure_description[i] < '9')
                   or figure_description[i] == '-') {
                digit[digit_point].push_back(figure_description[i]);
                if (figure_description[i + 1] < '0'
                    or figure_description[i + 1] > '9') {
                    digit_point = (digit_point + 1) % 2;
                }
                i++;
            }
            if (digit[1].size() > 0
                and (figure_description[i] == ','
                     or figure_description[i] == ')')) {
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
        return returned_points;
    }
    string get_figure_name(string figure_description)
    {
        string figure_name;
        for (auto symbol = figure_description.begin();
             symbol < figure_description.end() and *symbol != '(';
             symbol++) {
            if ((*symbol) != ' ') {
                figure_name.push_back(tolower(*symbol));
            }
        }
        return figure_name;
    }

protected:
    vector<vector<double>> points;
    string name;
    double perimeter;
    double square;
};