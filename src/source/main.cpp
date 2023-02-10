#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class figure {
public:
    string name;

private:
    vector<vector<int>> points;
};

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

vector<vector<double>> get_points(string figure_description)
{
    int i = figure_description.find('(');
    int points_quantity = 0;
    vector<vector<double>> returned_points(5);
    returned_points[0].reserve(3);
    string str;
    if (i == -1) {
        cout << "error\n";
    }
    int digit_point = 0;
    vector<string> digit(2);
    for (; figure_description[i] != ')'; i++) {
        if ((long unsigned int)points_quantity > returned_points.size() - 1) {
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

figure calculate_figure(string figure_description)
{
    cout << figure_description << "\n";
    string figure_name = get_figure_name(figure_description);
    figure ret_figure;
    vector<vector<double>> points = get_points(figure_description);
    for (long unsigned int i = 0; i < points.size(); i++) {
        for (long unsigned int k = 0; k < points[i].size(); k++) {
            cout << points[i][k] << ' ';
        }
        cout << endl;
    }
    return ret_figure;
}

int main()
{
    vector<string> user_input;
    string figure;
    while (getline(cin, figure) && figure != "") {
        user_input.push_back(figure);
    }
    for (vector<int>::size_type i = 0; i < user_input.size(); i++) {
        calculate_figure(user_input[i]);
    }
    return 0;
}
