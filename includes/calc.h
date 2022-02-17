#ifndef CALC_H
# define CALC_H

# include "data.h"
# include "vect.h"

t_vect	intersect_with_plane(t_camera *camera, t_vect *center, t_vect *normal);
bool	is_intersect_with_circle(t_camera *camera, void *object, int i);
bool	is_intersect_with_triangle(t_camera *camera, void *object, int i);
void	rotate_circle(void *object, int i);
void	rotate_triangle(void *object, int i);

#endif
