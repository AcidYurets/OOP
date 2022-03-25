#include "drawing.h"
#include "fig_struct.h"
#include "graph.h"

coord_point get_dot(point* dots, int n)
{
    coord_point dot = {dots[n].x, dots[n].y};
    return dot;
}


coord_point point_transform(coord_point dot, draw arg)
{
    coord_point tmp;

    tmp.x = dot.x + arg.w/2;
    tmp.y = dot.y + arg.h/2;

    return tmp;
}

void get_dots_to_link(coord_point& p1, coord_point& p2, points_data points, links_data links, int ind)
{
    link lnk = links.arr[ind];

    p1 = get_dot(points.arr, lnk.p1);
    p2 = get_dot(points.arr, lnk.p2);
}

void get_figure_dots(coord_point& p1, coord_point& p2, figure fig, int ind)
{
    get_dots_to_link(p1, p2, fig.points, fig.links, ind);
}

void draw_links(figure fig, draw arg, graphics a)
{
    coord_point p1, p2;

    for (int i = 0; i < fig.links.n; i++)
    {
        get_figure_dots(p1, p2, fig, i);
        draw_line(p1, p2, a, arg);
    }
}


void draw_line(coord_point p1, coord_point p2, graphics a, draw arg)
{
    p1 = point_transform(p1, arg);
    p2 = point_transform(p2, arg);

    my_addLine(a, p1.x, p2.x, p1.y, p2.y);
}

void my_addLine(graphics a, int x1, int x2, int y1, int y2)
{
    a.scene->addLine(x1, y1, x2, y2, a.pen);
}

void set_scene(draw arg, graphics& a)
{
    set(arg.gV, a, arg.w, arg.h);
}



