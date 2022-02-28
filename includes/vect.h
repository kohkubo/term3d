#ifndef VECT_H
# define VECT_H

# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include "data.h"

void	vect_print(const t_vect vect);
t_vect	vect_new(double x, double y, double z);
t_vect	vect_add(const t_vect vect1, const t_vect vect2);
t_vect	vect_sub(const t_vect *vect1, const t_vect *vect2);
t_vect	vect_mul(const t_vect vect1, const t_vect vect2);
t_vect	vect_div(const t_vect vect1, const t_vect vect2);
t_vect	vect_scalar_mul(const t_vect *vect, double scalar);
t_vect	vect_scalar_div(const t_vect *vect, double scalar);
double	vect_dot(const t_vect *vect1, const t_vect *vect2);
t_vect	vect_cross(const t_vect vect1, const t_vect vect2);
double	vect_len(const t_vect *vect);
t_vect	vect_normalize(const t_vect vect);
double	vect_distance(const t_vect *vect1, const t_vect *vect2);
t_vect	vect_inv(const t_vect *vect);
double	vect_det(const t_vect *vect1, const t_vect *vect2, const t_vect *vect3);
t_vect	vect_rotate(const t_vect *vect, const t_vect *axis, double radian);
double	vect_angle_radian(const t_vect vect1, const t_vect vect2);
bool	is_right_angle(const t_vect vect1, const t_vect vect2);
t_vect	vect_move(const t_vect *vect, const t_vect *dir, double len);

#endif
