#ifndef TERM3D_H
# define TERM3D_H

# include "vect.h"
# define WIDTH 50
# define HEIGHT 50
# define TOP 25
# define BOTTOM -25
# define LEFT -25
# define RIGHT 25
# define O ". "
# define X "  "
# define TOP_LEFT "\x1b[H"

typedef struct s_circle
{
	t_vect		circle_center;
	t_vect		circle_normal;
	double		circle_radius;
}				t_circle;

typedef struct s_torus
{
	t_vect		torus_center;
	t_vect		torus_normal;
	double		torus_radius;
	double		torus_tube_radius;
}				t_torus;

typedef struct s_data
{
	t_vect		camera_pos;
	t_vect		light_pos;
	t_vect		light_range;
	t_circle	*circle;
	t_torus		*torus;
}				t_data;

#endif
