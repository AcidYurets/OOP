#ifndef FIGURE_H
#define FIGURE_H
#include "fig_struct.h"
#include "drawing.h"
#include "operations.h"


figure& init();
void empty_figure(figure& fig);
void copy_figure(figure& fig, figure& tmp);
int load_figure_from_file(figure &ob, load_file file);

int draw_figure(figure fig, draw arg);

point get_center(points_data p);
int move_figure(figure& fig, move coeff);
int scale_figure(figure& fig, scale coeff);
int turn_figure(figure& fig, turn coeff);

#endif // FIGURE_H
