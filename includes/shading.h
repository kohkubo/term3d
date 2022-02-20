#ifndef SHADING_H
# define SHADING_H

#include "vect.h"
#include <string.h>

typedef struct s_light
{
	t_vect		pos;
	double		intensity;
}				t_light;

char	shading(t_vect *point, t_vect *normal);

#endif
