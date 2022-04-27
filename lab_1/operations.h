#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "point.h"

struct move
{
    int dx;
    int dy;
    int dz;
};

struct scale
{
    double kx;
    double ky;
    double kz;
    double cx;
    double cy;
    double cz;
};

struct turn
{
    int ox;
    int oy;
    int oz;
    double cx;
    double cy;
    double cz;
};

struct load_file
{
    const char* filename;
};

void move_point(point& dot, move coeff);
int move_points_array(points_data points, move coeff, point& center);

void scale_point(point& dot, scale coeff, point center);
int scale_points_array(points_data points, scale coeff, point center);

void x_turn_point(point& dot, double angle);
void y_turn_point(point& dot, double angle);
void z_turn_point(point& dot, double angle);
int turn_points_array(points_data points, turn coeff, point center);

#endif // OPERATIONS_H
