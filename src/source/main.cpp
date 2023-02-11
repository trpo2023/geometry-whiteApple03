#include <iostream>
#include <string>
#include <vector>
#include "../assistants/get_figure.hpp"

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

		for(auto i = all_figures.begin(); i < all_figures.end(); i++) {
				std::cout << "names: " << (*i).get_name() << std::endl;
		}

    return 0;
}
