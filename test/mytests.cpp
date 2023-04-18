
#include "../thirdparty/ctest.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <string>

#include <unistd.h>
#include <vector>

#include <get_figure.hpp>
struct data_base {
    std::vector<std::string> rows;
};
void get_base(data_base&);
data_base base;

// ************ circle ************************
CTEST(cirlce1, check_area)
{
    get_base(base);
    Figure* fig;
    fig = (get_figure_obj(base.rows[0]));
    ASSERT_DBL_NEAR_TOL(3.14, fig->get_square(), 0.01);
}

CTEST(cirlce1, check_perimetr)
{
    Figure* fig;
    fig = get_figure_obj(base.rows[0]);
    ASSERT_DBL_NEAR_TOL(6.28, fig->get_perimeter(), 0.01);
}

CTEST(cirlce1, check_name)
{
    Figure* fig;
    fig = (get_figure_obj(base.rows[0]));
    char* c = strcpy(new char[fig->get_name().length() + 1], fig->get_name().c_str());

    ASSERT_STR("circle", c);
}

// ************ triangle ************************

CTEST(triangle1, check_area)
{
    Figure* fig;
    fig = (get_figure_obj(base.rows[1]));
    ASSERT_DBL_NEAR_TOL(0.5, fig->get_square(), 0.01);
}

CTEST(triangle1, check_perimetr)
{
    Figure* fig;
    fig = get_figure_obj(base.rows[1]);
    ASSERT_DBL_NEAR_TOL(3.41, fig->get_perimeter(), 0.01);
}

CTEST(triangle, check_name)
{
    Figure* fig;
    fig = (get_figure_obj(base.rows[1]));
    char* c = strcpy(new char[fig->get_name().length() + 1], fig->get_name().c_str());
    ASSERT_STR("triangle", c);
}

// ************ polygon ************************

CTEST(polygon, check_area)
{
    Figure* fig;
    fig = (get_figure_obj(base.rows[2]));
    ASSERT_DBL_NEAR_TOL(8, fig->get_square(), 0.01);
}

CTEST(polygon, check_perimetr)
{
    Figure* fig;
    fig = get_figure_obj(base.rows[2]);
    ASSERT_DBL_NEAR_TOL(13.65, fig->get_perimeter(), 0.01);
}

CTEST(polygon, check_name)
{
    Figure* fig;
    fig = (get_figure_obj(base.rows[2]));
    char* c = strcpy(new char[fig->get_name().length() + 1], fig->get_name().c_str());
    ASSERT_STR("polygon", c);
}

// intersection

CTEST(circle2, check_intersection_with_triangle)
{
    Figure* fig;
    Figure* another;
    another = get_figure_obj(base.rows[1]);
    fig = (get_figure_obj(base.rows[0]));
    int flag = fig->check_intersection(*another);
    ASSERT_EQUAL(1, flag);
}

CTEST(circle2, check_intersection_with_polygon)
{
    Figure* fig;
    Figure* another;
    another = get_figure_obj(base.rows[2]);
    fig = (get_figure_obj(base.rows[0]));
    int flag = fig->check_intersection(*another);
    ASSERT_EQUAL(1, flag);
}

CTEST(triangle2, check_intersection_with_circle)
{
    Figure* fig;
    Figure* another;
    another = get_figure_obj(base.rows[0]);
    fig = (get_figure_obj(base.rows[1]));
    int flag = fig->check_intersection(*another);
    ASSERT_EQUAL(1, flag);
}
CTEST(triangle2, check_intersection_with_polygon)
{
    Figure* fig;
    Figure* another;
    another = get_figure_obj(base.rows[2]);
    fig = (get_figure_obj(base.rows[1]));
    int flag = fig->check_intersection(*another);
    ASSERT_EQUAL(1, flag);
}

CTEST(polygon2, check_intersection_with_circle)
{
    Figure* fig;
    Figure* another;
    another = get_figure_obj(base.rows[0]);
    fig = (get_figure_obj(base.rows[2]));
    int flag = fig->check_intersection(*another);
    ASSERT_EQUAL(1, flag);
}
CTEST(polygon2, check_intersection_with_triangle)
{
    Figure* fig;
    Figure* another;
    another = get_figure_obj(base.rows[1]);
    fig = (get_figure_obj(base.rows[2]));
    int flag = fig->check_intersection(*another);
    ASSERT_EQUAL(1, flag);
}