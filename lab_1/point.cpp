#include "cstdio"
#include <cstdlib>
#include "point.h"
#include "figure.h"
#include "error_handler.h"
#include "io.h"

int points_alloc(points_data& pts, int len)
{
    pts.n = len;
    pts.arr = (point*) calloc(len, sizeof(point));

    if (!pts.arr)
        return PTR_ALL_ERR;

    return NONE;
}


void points_free(points_data &pts)
{
    if (pts.arr)
        free(pts.arr);
}


int read_point(point* dot, FILE* f)
{
    if (fscanf(f, "%lf%lf%lf", &dot->x, &dot->y, &dot->z) != 3)
        return FILE_FORMAT_ERR;

    return NONE;
}


int read_n_points(point *dots, int n, FILE *f)
{
    int err = 0;
    for (int i = 0; !err && i < n; i++)
    {
        if (read_point(&dots[i], f))
            err = FILE_FORMAT_ERR;
    }
    return err;
}


int process_points(points_data &pts, FILE *f)
{
    int n;
    int err = 0;

    err = read_amount(&n, f);
    if (!err)
    {
        if (n)
            err = points_alloc(pts, n);
        else
            err = NO_DOTS;

        if (!err)
        {
            if ((err = read_n_points(pts.arr, n, f)) == FILE_FORMAT_ERR)
                points_free(pts);
        }
    }
    return err;
}

point get_point(point* arr, int i)
{
    return arr[i];
}

point get_center_from_points(points_data p)
{
    point* arr = p.arr;
    int n = p.n;

    point first = get_point(arr, 0);
    double x_max = first.x, x_min = first.x, y_max = first.y,
        y_min = first.y, z_max = first.z, z_min = first.z;
    for (int i = 0; i < n; i++)
    {
        point p = get_point(arr, i);
        if (p.x > x_max)
            x_max = p.x;
        if (p.x < x_min)
            x_min = p.x;
        if (p.y > y_max)
            y_max = p.y;
        if (p.y > y_max)
            y_max = p.y;
        if (p.z > z_max)
            z_max = p.z;
        if (p.z > z_max)
            z_max = p.z;
    }

    return point{ (x_max + x_min) / 2, (y_max + y_min) / 2, (z_max + z_min) / 2 };
}


