#ifndef SHADING_H
# define SHADING_H

# include "vect.h"
# include "data.h"
# include <string.h>

char	shading(t_camera *camera, t_light *light, t_object *hit);

#endif
