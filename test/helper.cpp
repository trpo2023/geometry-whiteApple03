#include <fstream>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>
struct data_base {
    std::vector<std::string> rows;
};
void get_base(data_base &base)
{

    // char buffer[PATH_MAX];
    // getcwd(buffer, sizeof(buffer));
    // std::string current_dir = buffer;
    std::string figure_one;

    std::ifstream file("../input/input2");

    if (file.is_open()) {
        while (getline(file, figure_one)) {
            (base).rows.push_back(figure_one);
        }
        file.close();
    }
}