#include "../Figure/Figure.h"
#include <algorithm>
#include <iostream>
#include <vector>

#include <map>

using namespace std;
class Circle : public Figure {
public:
    Circle(string figure_description) : Figure(figure_description)
    {
        radius = get_radius(figure_description);
        cout << "radius: " << radius << endl;
    }

    double get_radius(string figure_description)
    {
        int i = figure_description.rfind(')');
        if (i == -1) {
            cout << "error\n";
        }
        string radius = "";
        for (; i >= 0; i--) {
            while ((figure_description[i] > '0' and figure_description[i] < '9')
                   or figure_description[i] == '-') {
                radius.push_back(figure_description[i]);
                i--;
            }
            if (radius.size() > 0 and figure_description[i] == ',') {
                reverse(radius.begin(), radius.end());
                return stod(radius);
            }
        }
				cout << "error: did't find the radius\n";
				return -1;
    }

    double get_perimetr()
    {
        return perimeter;
    }

private:
    double radius;
};