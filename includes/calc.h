#ifndef CALC_H
# define CALC_H

# include "data.h"
# include "vect.h"

t_vect	camera_ray(t_camera *camera, int x, int y);
bool	is_intersect_with_triangle(t_camera *camera, t_object *object);
bool	is_intersect_with_sphere(t_camera *camera, t_vect pos, double radius);
bool	is_intersect_with_vector(t_camera *camera, t_vect pos, t_vect edge);
void	camera_rotate(t_camera *camera);

#endif
