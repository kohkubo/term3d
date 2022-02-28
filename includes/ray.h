#ifndef RAY_H
# define RAY_H

# include "data.h"
# include "vect.h"

void		set_camera_ray(\
t_camera *camera, t_base_info *base_info, int x, int y);
t_object	*intersect(t_data *data, t_camera *camera);
double		intersect_with_triangle_surface(t_camera *camera, t_object *object);

#endif
