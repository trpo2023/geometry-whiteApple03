#include "../assistants/get_figure.hpp"
#include <iostream>
#include <string>
#include <vector>
double get_vector_multi(double ax, double ay, double bx, double by)
{
    return ax * by - bx * ay;
}

bool check_intersection(Figure first_figure, Figure second_figure)
{
    std::vector<std::vector<double>> first_coord = first_figure.get_points();
    std::vector<std::vector<double>> second_coord = second_figure.get_points();

    double* vs = new double[4];
    for (unsigned int i = 0; i < first_coord.size() - 1; i++) {
        double x1 = first_coord[i][0], y1 = first_coord[i][1],
               x2 = first_coord[i + 1][0], y2 = first_coord[i + 1][1];
        // std::cout << "!!!!!!!!!!!!!!!!!first otrezok!!!!!!!!!!!!!!!\n";
        // std::cout << "first point: " << x1 << ' ' << y1
        //           << "\nsecond point: " << x2 << ' ' << y2 << std::endl;

        for (unsigned int k = 0; k < second_coord.size() - 1; k++) {
            double x3 = second_coord[k][0], y3 = second_coord[k][1],
                   x4 = second_coord[k + 1][0], y4 = second_coord[k + 1][1];
            // std::cout << "first point2: " << x3 << ' ' << y3
            //           << "\nsecond point2: " << x4 << ' ' << y4 << std::endl;

            vs[0] = get_vector_multi(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
            vs[1] = get_vector_multi(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
            vs[2] = get_vector_multi(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
            vs[3] = get_vector_multi(x2 - x1, y2 - y1, x4 - x1, y4 - y1);
            if ((vs[0] * vs[1] <= 0 and vs[2] * vs[3] <= 0) or (((x4-x3)*(y1-y3)-(x1-x3)*(y4-y3)==0)or((x2-x1)*(y1-y3)-(y2-y1)*(x1-x3)==0))) {
                return true;
            }
        }
    }
    return false; //-1  1 2 2.52 2 1 -1 3
}

int main()
{
    std::vector<std::string> all_figure_names = {"circle"};
    std::vector<std::string> user_input;
    std::string figure_one;

    while (getline(std::cin, figure_one) && figure_one != "") {
        user_input.push_back(figure_one);
    }
    std::vector<Figure> all_figures;
    for (std::vector<int>::size_type i = 0; i < user_input.size(); i++) {
        all_figures.push_back(get_figure_obj(user_input[i]));
    }

    for (unsigned int i = 0; i < all_figures.size(); i++) {
        std::cout << i + 1 << "." << all_figures[i].get_name() << "\n"
                  << "  perimeter = " << all_figures[i].get_perimeter() << "\n"
                  << "  area = " << all_figures[i].get_square() << '\n'
                  << "  intersects:\n";

        for (unsigned int k = 0; k < all_figures.size(); k++) {
            if (k == i) {
                continue;
            }
            if (check_intersection(all_figures[i], all_figures[k])) {
                std::cout << "    " << k + 1 << "." << all_figures[k].get_name()
                          << "\n";
            }
        }
    }
    return 0;
}
