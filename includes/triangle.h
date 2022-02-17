#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "data.h"
# include "vect.h"

bool	is_intersect_with_triangle(t_camera *camera, t_triangle *triangle);
void	rotate_triangle(t_data *data);

#endif
