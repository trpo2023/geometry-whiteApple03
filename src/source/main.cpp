#include <iostream>
#include <string>
#include <vector>
#include "../assistants/get_figure.hpp"


int main()
{
	std::vector<std::string> user_input;
    std::string figure_one;

    while (getline(std::cin, figure_one) && figure_one != "") {
        user_input.push_back(figure_one);
    }
    std::vector<Figure*> all_figures;
    for (std::vector<int>::size_type i = 0; i < user_input.size(); i++) {
        all_figures.push_back(get_figure_obj(user_input[i]));
    }

    for (unsigned int i = 0; i < all_figures.size(); i++) {
        std::cout << i + 1 << "." << all_figures[i]->get_name() << "\n"
                  << "  perimeter = " << all_figures[i]->get_perimeter() << "\n"
                  << "  area = " << all_figures[i]->get_square() << '\n'
                  << "  intersects:\n";

        for (unsigned int k = 0; k < all_figures.size(); k++) {
            if (k == i) {
                continue;
            }
            if (all_figures[i]->check_intersection(*all_figures[k])) {
                std::cout << "    " << k + 1 << "." << all_figures[k]->get_name()
                          << "\n";
            }
        }
    }
    return 0;
}
