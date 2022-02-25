#ifndef RAY_H
# define RAY_H

# include "data.h"
# include "vect.h"

t_vect		camera_ray(\
t_vect *camera_pos, t_base_info *base_info, int x, int y);
t_object	*intersect(t_data *data, t_camera *camera);
double		intersect_with_triangle_surface(t_camera *camera, t_object *object);

#endif
