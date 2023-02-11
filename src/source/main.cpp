#include "../figures/Circle.h"
#include <iostream>
#include <string>
#include <vector>


using namespace std;


int main()
{
    vector<string> user_input;
    string figure_one;
    while (getline(cin, figure_one) && figure_one != "") {
        user_input.push_back(figure_one);
    }
    Circle circle(user_input[0]);
    // for (vector<int>::size_type i = 0; i < user_input.size(); i++) {
    //     circle(user_input[i]);
    // }
    vector<vector<double>> points = circle.get_points();

    for (unsigned int i = 0; i < points.size(); i++) {
        for (unsigned int k = 0; k < points[i].size(); k++) {
            cout << points[i][k] << ' ';
        }
        cout << endl;
    }
    return 0;
}
