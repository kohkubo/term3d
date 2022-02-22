#ifndef DATA_H
# define DATA_H

# include <stdbool.h>
# include <float.h>
# include <math.h>
# define WIDTH 50
# define HEIGHT 50
# define FOCUS_DISTANCE 20
# define O ". "
# define X "  "
/*
TOP_LEFTは標準出力の位置を固定するためのものです
これを出力の最初に行うことで、標準出力を使ったアニメーションができます
*/
# define TOP_LEFT "\x1b[H"
# define DISABLE_CURSOR "\033[?25l"
# define ENABLE_CURSOR "\033[?25h"
/*
最大制度 DBL_EPSILON
kawadaさんがEPSILONは 0.000001 くらいがいいって言ってた
*/
# define EPSILON 0.000001

# ifndef OBJECT_SIZE_MAX
#  define OBJECT_SIZE_MAX 420
# endif

# define DOT_SIZE 1
# define DOT_DENSITY 1

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct s_camera
{
	t_vect		pos;
	t_vect		up;
	t_vect		right;
	t_vect		normal;
	t_vect		lookat;
	t_vect		ray;
	t_vect		normal_axis;
	double		rotate_angle;
}				t_camera;

typedef struct s_light
{
	t_vect		pos;
	double		intensity;
}				t_light;

typedef struct s_object
{
	t_vect		pos1;
	t_vect		pos2;
	t_vect		pos3;
}				t_object;

typedef struct s_data
{
	t_camera	camera;
	t_light		light;
	t_object	object[OBJECT_SIZE_MAX];
	char		canvas[HEIGHT][WIDTH];
	int			count;
	double		(*intersect)(t_camera *, t_object *);
}				t_data;

typedef struct s_canvas
{
	t_data		data;
	int			y;
	char		line[WIDTH];
}				t_canvas;

bool			is_equal(double a, double b);
bool			less(double a, double b);
bool			less_equal(double a, double b);
double			radian(double degree);
double			degree(double radian);

#endif
