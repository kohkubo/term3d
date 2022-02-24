#ifndef DATA_H
# define DATA_H

# include <stdbool.h>
# include <float.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <pthread.h>
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
# define OBJECT_SIZE_MAX INT_MAX

# define END			"\033[0m"
# define BOLD			"\033[1m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define UNDERLINE		"\033[4m"
# define BOLD_UNDERLINE	"\033[1;4m"

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

typedef struct s_camera
{
	int			width;
	int			height;
	t_vect		pos;
	t_vect		up;
	t_vect		right;
	t_vect		normal;
	t_vect		lookat;
	t_vect		ray;
	t_vect		normal_axis;
	t_vect		center_object_pos;
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
	t_vect		edge1;
	t_vect		edge2;
	t_vect		edge3;
	t_vect		normal;
}				t_object;

typedef struct s_config
{
	char		*charset;
	char		*color;
}				t_config;

typedef struct s_control
{
	void		(*control)(t_camera *);
	char		key;
}				t_control;

typedef struct s_data
{
	t_camera	camera;
	t_light		light;
	t_object	*object;
	char		*canvas;
	int			count;
	double		(*intersect)(t_camera *, t_object *);
	t_config	config;
}				t_data;

typedef struct s_thread_line
{
	pthread_t	thread;
	t_data		data;
	int			y;
}				t_thread_line;

bool			is_equal(double a, double b);
bool			less(double a, double b);
bool			less_equal(double a, double b);
double			radian(double degree);
double			degree(double radian);

void			*ft_xcalloc(size_t count, size_t size);
void			exit_error(char *errmsg);
FILE			*fopen_wrapper(char *filepath);
double			strtod_wrapper(char *str);

void			end_handler(int sig, siginfo_t *info, void *ucontext);
void			receiver(void handler(int, siginfo_t *, void *));

#endif
