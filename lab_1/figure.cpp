#include "cstdio"
#include <cstdlib>
#include "figure.h"
#include "error_handler.h"
#include "point.h"
#include "link.h"
#include "drawing.h"
#include "graph.h"
#include "operations.h"
#include "io.h"

figure& init()
{
    static figure fig;

    fig.points.n = 0;
    fig.points.arr = NULL;

    fig.links.n = 0;
    fig.links.arr = NULL;

    fig.center = point{ 0, 0, 0 };

    return fig;
}


void empty_figure(figure& fig)
{
    fig.points.n = 0;
    points_free(fig.points);

    fig.links.n = 0;
    links_free(fig.links);
}

void copy_figure(figure& fig, figure& tmp)
{
    fig.points.n = tmp.points.n;
    fig.points.arr = tmp.points.arr;

    fig.links.n = tmp.links.n;
    fig.links.arr = tmp.links.arr;
}

void free_figure(figure fig)
{
    links_free(fig.links);
    points_free(fig.points);
}

int read_figure_data(figure& fig_tmp, FILE* f)
{
    int err = process_points(fig_tmp.points, f);
    if (!err)
    {
        err = process_links(fig_tmp.links, f);
        if (err != NONE)
            points_free(fig_tmp.points);
    }

    return err;
}

int links_to_points_check(figure fig)
{
    int err = NONE;
    for (int i = 0; i < fig.links.n; i++)
    {
        if (fig.links.arr[i].p1 > fig.points.n - 1 || fig.links.arr[i].p2 > fig.points.n - 1)
            err = INCORRECT_LINKS;
    }

    return err;
}

int load_figure_from_file(figure& fig, load_file file)
{
    const char *filename = file.filename;
    FILE *f = fopen(filename, "r");
    if (!f)
        return FILE_NOT_FOUND;

    figure fig_tmp = init();
    int err = read_figure_data(fig_tmp, f);
    fclose(f);

    if (!err)
    {
        err = links_to_points_check(fig_tmp);
        if (err)
            free_figure(fig_tmp);
    }

    if (!err)
    {
        empty_figure(fig);
        copy_figure(fig, fig_tmp);
        get_figure_center(fig);
    }

    return err;
}


int draw_figure(figure fig, draw arg)
{
    graphics a;

    int err = init_graph(a, arg.gV);
    if (err)
        return err;

    draw_links(fig, arg, a);

    set_scene(arg, a);

    return err;
}


void get_figure_center(figure& fig)
{
    fig.center = get_center(fig.points);
}

int move_figure(figure& fig, move coeff)
{
    return move_points_array(fig.points, coeff, fig.center);
}

int scale_figure(figure& fig, scale coeff)
{
    return scale_points_array(fig.points, coeff, fig.center);
}

int turn_figure(figure& fig, turn coeff)
{
    return turn_points_array(fig.points, coeff, fig.center);
}
