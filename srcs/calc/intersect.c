#include "calc.h"

t_object	*intersect(t_data *data)
{
	int			i;
	double		shortest;
	double		t;
	t_object	*hit;

	t = DBL_MAX;
	hit = NULL;
	i = 0;
	while (i < data->count)
	{
		shortest = t;
		t = fmin(t, data->intersect(&data->camera, &data->object[i]));
		if (t < shortest)
			hit = &data->object[i];
		i++;
	}
	data->camera.lookat = vect_add(\
	data->camera.pos, vect_scalar_mul(&data->camera.ray, t));
	return (hit);
}
