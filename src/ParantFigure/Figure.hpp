#ifndef Figure_HPP
#define Figure_HPP
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

class Figure {
public:
    Figure(std::string figure_description, std::string figure_name);
    void handling_incorrect_name(std::string figure_description, int left_border, int right_border);

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
    void get_name_borders(std::string figure_description, int* left_border, int* right_border);

    std::vector<std::vector<double>> get_points(std::string figure_description);

protected:
    double get_segment_length(std::vector<double> first_point, std::vector<double> second_point)
    {
        return sqrt(pow(second_point[0] - first_point[0], 2) + pow(second_point[1] - first_point[1], 2));
    }
    std::vector<std::vector<double>> points;
    std::string name;
    double perimeter;
    double square;
};
#endif