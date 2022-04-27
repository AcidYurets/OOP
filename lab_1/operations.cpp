#include "math.h"
#include "operations.h"
#include "error_handler.h"
#include "figure.h"
#include "qdebug"

#define PI 3.1415926535 

void move_point(point& dot, move coeff)
{
    dot.x += coeff.dx;
    dot.y += coeff.dy;
    dot.z += coeff.dz;
}

int move_points_array(points_data points, move coeff, point& center)
{
    point* pts = points.arr;
    int n = points.n;

    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        move_point(pts[i], coeff);

    center.x += coeff.dx;
    center.y += coeff.dy;
    center.z += coeff.dz;

    return err;
}


void scale_point(point& dot, scale coeff, point c)
{
    dot.x = coeff.kx * dot.x + (1 - coeff.kx) * c.x;
    dot.y = coeff.ky * dot.y + (1 - coeff.ky) * c.y;
    dot.z = coeff.kz * dot.z + (1 - coeff.kz) * c.z;
}

int scale_points_array(points_data points, scale coeff, point center)
{
    point* pts = points.arr;
    int n = points.n;

    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        scale_point(pts[i], coeff, center);

    return err;
}

void x_turn_point(point& dot, double angle)
{
    angle *= PI / 180;
   
    point buf = dot;
    dot.y = (buf.y) * cosf(angle) + (buf.z) * sinf(angle);
    dot.z = (buf.y) * sinf(-angle) + (buf.z) * cosf(angle);
}

void y_turn_point(point& dot, double angle)
{
    angle *= PI / 180;

    point buf = dot;
    dot.x = (buf.x) * cosf(angle) + (buf.z) * sinf(angle);
    dot.z = (buf.x) * sinf(-angle) + (buf.z) * cosf(angle);
}

void z_turn_point(point& dot, double angle)
{
    angle *= PI / 180;

    point buf = dot;
    dot.x = (buf.x) * cosf(angle) + (buf.y) * sinf(angle);
    dot.y = (buf.x) * sinf(-angle) + (buf.y) * cosf(angle);
}


int turn_points_array(points_data points, turn coeff, point center)
{
    point* pts = points.arr;
    int n = points.n;

    if (!pts)
        return NO_DOTS;
    int err = 0;

    for (int i = 0; i < n; i++)
    {
        move move_to_center = { -center.x, -center.y, -center.z };
        move_point(pts[i], move_to_center);

        x_turn_point(pts[i], coeff.ox);
        y_turn_point(pts[i], coeff.oy);
        z_turn_point(pts[i], coeff.oz);

        move move_back = { center.x, center.y, center.z };
        move_point(pts[i], move_back);
    }

    return err;
}
