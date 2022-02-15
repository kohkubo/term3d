#ifndef DATA_H
# define DATA_H

# include <stdbool.h>
# include "vect.h"
# define WIDTH 50
# define HEIGHT 50
/*
defineの引数は一つでないとnormエラー
#define TOP HEIGHT / 2 とは書けないです
*/
# define TOP 25
# define BOTTOM -25
# define LEFT -25
# define RIGHT 25
# define O ". "
# define X "  "
/*
TOP_LEFTは標準出力の位置を固定するためのものです
これを出力の最初に行うことで、標準出力を使ったアニメーションができます
*/
# define TOP_LEFT "\x1b[H"

typedef struct s_circle
{
	t_vect		center;
	t_vect		normal;
	double		radius;
}				t_circle;

typedef struct s_torus
{
	t_vect		center;
	t_vect		normal;
	double		radius;
	double		tube_radius;
}				t_torus;

typedef struct s_camera
{
	t_vect		pos;
	t_vect		up;
	t_vect		lookat;
	double		screen_dist;
	t_vect		screen_center;
}				t_camera;

typedef struct s_light
{
	t_vect		pos;
	t_vect		range;
}				t_light;

typedef struct s_data
{
	t_light		*light;
	t_camera	*camera;
	t_circle	*circle;
	t_torus		*torus;
}				t_data;

#endif
