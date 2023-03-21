#include "assistants/get_figure.hpp"
#include <fstream>
#include <iostream>
#include <limits.h>
#include <string>
#include <unistd.h>
#include <vector>

int main(int argc, char** argv)
{
    bool directory = false;
    std::string path = "input/input";
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            int k = 1;
            while (argv[i][k] != '\0') {
                if (argv[i][k] == 'd') {
                    directory = true;
                    if (i + 1 < argc) {
                        path = argv[i + 1];
                        i++;
                    }
                    break;
                }
                k++;
            }
        }
    }

    std::vector<std::string> user_input;
    std::string figure_one;

    char buffer[PATH_MAX];
    getcwd(buffer, sizeof(buffer));
    std::string current_dir = buffer;

    if (directory) {
        path = current_dir + "/" + path;
        std::cout << path << '\n';
        std::ifstream file(path);
        if (file.is_open()) {
            while (getline(file, figure_one)) {
                user_input.push_back(figure_one);
            }
            file.close();
        } else {
            std::cout << "\a\e[1;31mОШИБКА: файл \e[0m\e[35m\e[0m\e[1;31m не "
                         "существует!\e[0m\n";
            exit(1);
        }

    } else {
        while (getline(std::cin, figure_one) && figure_one != "")
            user_input.push_back(figure_one);
    }

    std::vector<Figure*> all_figures;
    for (std::vector<int>::size_type i = 0; i < user_input.size(); i++) {
        all_figures.push_back(get_figure_obj(user_input[i]));
    }
    std::ofstream output(current_dir + "/output");
    for (unsigned int i = 0; i < all_figures.size(); i++) {
        if (all_figures[i]->get_name() == "error") {
            continue;
        }
        output << i + 1 << "." << all_figures[i]->get_name() << "\n"
               << "  perimeter = " << all_figures[i]->get_perimeter() << "\n"
               << "  area = " << all_figures[i]->get_square() << '\n'
               << "  intersects:\n";

        for (unsigned int k = 0; k < all_figures.size(); k++) {
            if (k == i) {
                continue;
            }
            if (all_figures[i]->check_intersection(*all_figures[k])) {
                output << "    " << k + 1 << "." << all_figures[k]->get_name() << "\n";
            }
        }
    }
    return 0;
}
