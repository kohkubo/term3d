#ifndef CALC_H
# define CALC_H

# include "data.h"
# include "vect.h"

t_vect	camera_ray(t_camera *camera, int x, int y);
double	update_t(double shortest, double t);
double	intersect_with_triangle(t_camera *camera, t_object *object);
double	intersect_with_sphere(t_camera *camera, t_vect pos, double radius);
double	intersect_with_vector(t_camera *camera, t_vect pos, t_vect edge);
void	camera_rotate(t_camera *camera);

#endif
