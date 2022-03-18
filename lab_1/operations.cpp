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

int move_points_array(point* pts, int n, move coeff, point& center)
{
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

int scale_points_array(point* pts, int n, scale coeff, point center)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    for(int i = 0; i < n; i++)
        scale_point(pts[i], coeff, center);

    return err;
}

void x_turn_point(point& dot, double angle, point c)
{
    angle *= PI / 180;
   
    point buf = dot;
    dot.y = c.y + (buf.y - c.y) * cosf(angle) + (buf.z - c.z) * sinf(angle);
    dot.z = c.z + (buf.y - c.y) * sinf(-angle) + (buf.z - c.z) * cosf(angle);
}

void y_turn_point(point& dot, double angle, point c)
{
    angle *= PI / 180;

    point buf = dot;
    dot.x = c.x + (buf.x - c.x) * cosf(angle) + (buf.z - c.z) * sinf(angle);
    dot.z = c.z + (buf.x - c.x) * sinf(-angle) + (buf.z - c.z) * cosf(angle);
}

void z_turn_point(point& dot, double angle, point c)
{
    angle *= PI / 180;

    point buf = dot;
    dot.x = c.x + (buf.x - c.x) * cosf(angle) + (buf.y - c.y) * sinf(angle);
    dot.y = c.y + (buf.x - c.x) * sinf(-angle) + (buf.y - c.y) * cosf(angle);
}


int turn_points_array(point* pts, int n, turn coeff, point center)
{
    if(!pts)
        return NO_DOTS;
    int err = 0;

    points_data p_d{ n, pts };
    //point center = get_center(p_d);
    for(int i = 0; i < n; i++)
    {
        x_turn_point(pts[i], coeff.ox, center);
        y_turn_point(pts[i], coeff.oy, center);
        z_turn_point(pts[i], coeff.oz, center);
    }

    return err;
}
