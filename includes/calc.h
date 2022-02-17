#ifndef CALC_H
# define CALC_H

# include "data.h"
# include "vect.h"

t_vect	intersect_with_plane(t_camera *camera, t_vect *center, t_vect *normal);
bool	is_intersect_with_circle(t_camera *camera, t_circle *circle);
bool	is_intersect_with_triangle(t_camera *camera, t_triangle *triangle);
void	rotate_circle(t_data *data);
void	rotate_triangle(t_data *data);

#endif
