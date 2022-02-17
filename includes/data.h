#ifndef DATA_H
# define DATA_H

# include <stdbool.h>
# include <float.h>
# include <math.h>
# define WIDTH 30
# define HEIGHT 30
# define FOCUS_DISTANCE 20
# define O ". "
# define X "  "
/*
TOP_LEFTは標準出力の位置を固定するためのものです
これを出力の最初に行うことで、標準出力を使ったアニメーションができます
*/
# define TOP_LEFT "\x1b[H"
/*
最大制度 DBL_EPSILON
kawadaさんがEPSILONは 0.000001 くらいがいいって言ってた
*/
# define EPSILON 0.000001

# define OBJECT_COUNT 10000

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct s_circle
{
	t_vect		center;
	t_vect		normal;
	double		radius;
}				t_circle;

typedef struct s_triangle
{
	t_vect		vert1;
	t_vect		vert2;
	t_vect		vert3;
	t_vect		normal;
}				t_triangle;

typedef struct s_camera
{
	t_vect		pos;
	t_vect		lookat;
	t_vect		ray;
}				t_camera;

typedef enum e_type
{
	CIRCLE,
	TRIANGLE,
}				t_type;

typedef struct s_data
{
	t_camera	*camera;
	t_circle	circle[OBJECT_COUNT];
	t_triangle	triangle[OBJECT_COUNT];
	void		*object;
	int			count;
	t_type		type;
}				t_data;

bool			is_equal(double a, double b);
bool			less(double a, double b);
bool			less_equal(double a, double b);
double			radian(double degree);
double			degree(double radian);

#endif
