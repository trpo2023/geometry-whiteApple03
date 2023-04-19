#ifndef Figure_HPP
#define Figure_HPP
#include <fstream>

#include <math.h>
#include <string>
#include <vector>

class Figure {
public:
    Figure(std::string figure_description, std::string figure_name);
    void error_highlighting(std::string figure_description, int left_border, int right_border);

    void print_mes(std::string message)
    {
        std::ofstream output("output", std::ios::app);
        if (output.is_open()) {
            output << message;
        }
    }
    int check_correctness_of_data(std::string figure_description, std::string config)
    {
        int index_config = 0;
        bool com_is_calc = false;
        for (unsigned int i = point_name_borders->right_border + 1; i < figure_description.size();
             i++) {
            int rc = 0;
            if (!com_is_calc and config[index_config] == '{') {
                int k = 0;
                int cnt_comma = 1;
                while (figure_description.find(',', k) != (size_t)-1) {
                    cnt_comma++;
                    k = figure_description.find(',', k) + 1;
                }
                com_is_calc = true;
                config.insert(config.find('}') + 1, std::to_string(cnt_comma));
                index_config++;
            }
            if (config[index_config] == '}') {
                int tmp_index = 0;
                if (config[index_config + 1] == '1') {
                    index_config += 2;
                    i--;
                    continue;
                } else {
                    rc = find_comma(",", figure_description, i, tmp_index);
                    if (rc == -1) {
                        return -1;
                    }
                }
                config[index_config + 1] = ((config[index_config + 1] - '0') - 1) + '0';
                index_config = config.rfind('{', index_config) + 1;
            }
            rc = find_bracket(config, figure_description, i, index_config);
            if (rc == -1) {
                return -1;
            }
            if (rc) {
                i--;
                continue;
            }
            rc = find_digit(config, figure_description, i, index_config);
            if (rc == -1) {
                return -1;
            }
            if (rc) {
                i--;
                continue;
            }
            rc = find_comma(config, figure_description, i, index_config);
            if (rc == -1) {
                return -1;
            }
            if (rc) {
                i--;
                continue;
            }
            rc = find_close_bracket(config, figure_description, i, index_config);
            if (rc == -1) {
                return -1;
            }
            if (rc) {
                i--;
                continue;
            }
        }
        return 0;
    }

    virtual bool check_intersection(Figure& another_fig)
    {
        return 0;
    }
    virtual int get_some_infomation()
    {
        return 0;
    }

    std::vector<std::vector<double>> get_points()
    {
        return points;
    }
    std::string get_name()
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
    int find_close_bracket(
            std::string config, std::string figure_description, unsigned int& i, int& index_config)
    {
        if ((unsigned int)index_config >= config.size()) {
            while (i < figure_description.size()) {
                if (figure_description[i] != ' ') {
                    error_highlighting(figure_description, i, i);

                    print_mes(" incorrect input format: expected nothing\n");
                    // exit(-1);(-1);
                    name = "error";
                    return -1;
                }
                i++;
            }
        }
        if (config[index_config] == ')') {
            while (i < figure_description.size() and figure_description[i] != ')') {
                if (figure_description[i] != ' ') {
                    error_highlighting(figure_description, i, i);
                    print_mes(" incorrect input format: expected symbol ')'\n");
                    name = "error";
                    return -1;
                }
                i++;
            }
            index_config++;
            i++;
            return 1;
        }

        return 0;
    }
    int find_comma(
            std::string config, std::string figure_description, unsigned int& i, int& index_config)
    {
        if (config[index_config] == ',') {
            while (i < figure_description.size() and figure_description[i] != ',') {
                if (figure_description[i] != ' ') {
                    error_highlighting(figure_description, i, i);
                    print_mes(" incorrect input format: expected symbol ','\n");
                    // exit(-1);(-1);
                    name = "error";
                    return -1;
                }
                i++;
            }
            index_config++;
            i++;
            return 1;
        }

        return 0;
    }
    int find_digit(
            std::string config, std::string figure_description, unsigned int& i, int& index_config)
    {
        if (config[index_config] == 'd') {
            while (i < figure_description.size()) {
                if ((figure_description[i] >= '0' and figure_description[i] <= '9')
                    or figure_description[i] == '-') {
                    break;
                }
                if (figure_description[i] != ' ') {
                    error_highlighting(figure_description, i, i);
                    print_mes(" incorrect input format: expected digit\n");
                    name = "error";
                    return -1;
                }
                i++;
            }
            unsigned int start_of_digit = i;
            unsigned int end_of_digit = i;
            int tmp_i = i;
            while (figure_description[tmp_i] != ' ' and figure_description[tmp_i] != ')'
                   and figure_description[tmp_i] != ',') {
                end_of_digit++;
                tmp_i++;
            }

            int dash = 0;
            int8_t decimal_point = 0;
            for (i = start_of_digit; i < end_of_digit; ++i) {
                if (figure_description[i] == '.') {
                    decimal_point++;
                }
                if (figure_description[i] == '-') {
                    dash++;
                }
                if (decimal_point > 1) {
                    error_highlighting(figure_description, start_of_digit, end_of_digit - 1);
                    print_mes(" there can be only one dot in a number\n");
                    // exit(-1);(-1);
                    name = "error";
                    return -1;
                }
                if (dash > 1) {
                    error_highlighting(figure_description, start_of_digit, end_of_digit - 1);
                    print_mes(" there can be only one dash in a number\n");
                    // exit(-1);(-1);
                    name = "error";
                    return -1;
                }
                if ((figure_description[i] < '0' or figure_description[i] > '9')
                    and (figure_description[i] != '.' and figure_description[i] != '-')) {
                    error_highlighting(figure_description, i, i);
                    print_mes(" incorrect input format: expected digit\n");
                    // exit(-1);(-1);
                    name = "error";
                    return -1;
                }
            }
            index_config++;
            return 1;
        }
        return 0;
    }
    int find_bracket(
            std::string config, std::string figure_description, unsigned int& i, int& index_config)
    {
        if (config[index_config] == '(') {
            while (i < figure_description.size() and figure_description[i] != '(') {
                if (figure_description[i] != ' ') {
                    error_highlighting(figure_description, i, i);
                    print_mes(" incorrect input format: expected symbol '('\n");
                    // exit(-1);(-1);
                    name = "error";
                    return -1;
                }
                i++;
            }
            index_config++;
            i++;
            return 1;
        }

        return 0;
    }
    std::string get_config(std::string figure_name);
    void get_name_borders(std::string figure_description, int& left_border, int& right_border);

    std::vector<std::vector<double>>
    get_points(std::string figure_description, std::string figure_name);

protected:
    double get_segment_length(std::vector<double> first_point, std::vector<double> second_point)
    {
        return sqrt(
                pow(second_point[0] - first_point[0], 2)
                + pow(second_point[1] - first_point[1], 2));
    }
    std::vector<std::vector<double>> points;
    std::string name;
    double perimeter;
    double square;
    struct name_borders {
        int left_border;
        int right_border;
    };
    name_borders* point_name_borders;
};
#endif