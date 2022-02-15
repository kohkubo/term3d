#ifndef VECT_H
# define VECT_H

# include <stdio.h>
# include <math.h>

typedef struct s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

void	vect_print(t_vect vect);
t_vect	vect_new(double x, double y, double z);
t_vect	vect_dup(t_vect vect);
t_vect	vect_add(t_vect vect1, t_vect vect2);
t_vect	vect_sub(t_vect vect1, t_vect vect2);
t_vect	vect_mul(t_vect vect1, t_vect vect2);
t_vect	vect_div(t_vect vect1, t_vect vect2);
t_vect	vect_scalar_mul(t_vect vect, double scalar);
t_vect	vect_scalar_div(t_vect vect, double scalar);
double	vect_dot(t_vect vect1, t_vect vect2);
t_vect	vect_cross(t_vect vect1, t_vect vect2);
double	vect_len(t_vect vect);
t_vect	vect_normalize(t_vect vect);
double	vect_distance(t_vect vect1, t_vect vect2);
t_vect	vect_inv(t_vect vect);
double	vect_det(t_vect vect1, t_vect vect2, t_vect vect3);
t_vect	vect_rotate(t_vect vect, t_vect axis, double angle);
double	vect_angle(t_vect vect1, t_vect vect2);
#endif
