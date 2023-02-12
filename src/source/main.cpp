#include "../assistants/get_figure.hpp"
#include <iostream>
#include <string>
#include <vector>


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
        std::cout << i + 1 << ". " << all_figures[i].get_name() << "\n\t"
                  << "perimeter = " << all_figures[i].get_perimeter() << "\n\t"
                  << "area = " << all_figures[i].get_square() << '\n';
    }
    return 0;
}
