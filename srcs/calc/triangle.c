#include "calc.h"

double	update_t(double shortest, double t)
{
	if (t < 0)
		return (shortest);
	if (t < shortest)
		return (t);
	return (shortest);
}

double	intersect_with_vector(t_camera *camera, t_vect pos, t_vect edge)
{
	double	len;
	t_vect	normal;
	double	t;

	len = vect_len(edge);
	normal = vect_normalize(edge);
	t = DBL_MAX;
	if (len == 0)
		return (t);
	while (len > 0)
	{
		t = update_t(t, intersect_with_sphere(camera, pos, DOT_SIZE));
		pos = vect_move(pos, normal, DOT_DENSITY);
		len -= DOT_DENSITY;
	}
	return (t);
}

#ifndef DOT

double	intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	t_vect	edge[3];
	double	t;

	edge[0] = vect_sub(triangle->pos2, triangle->pos1);
	edge[1] = vect_sub(triangle->pos3, triangle->pos1);
	edge[2] = vect_sub(triangle->pos3, triangle->pos2);
	t = DBL_MAX;
	t = update_t(t, intersect_with_vector(camera, triangle->pos1, edge[0]));
	t = update_t(t, intersect_with_vector(camera, triangle->pos1, edge[1]));
	t = update_t(t, intersect_with_vector(camera, triangle->pos2, edge[2]));
	return (t);
}

#else

bool	is_intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	bool	ret[3];

	ret[0] = is_intersect_with_sphere(camera, triangle->pos1, 0.8);
	ret[1] = is_intersect_with_sphere(camera, triangle->pos2, 0.8);
	ret[2] = is_intersect_with_sphere(camera, triangle->pos3, 0.8);
	return (ret[0] || ret[1] || ret[2]);
}

#endif

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
		t = update_t(t, data->intersect(&data->camera, &data->object[i]));
		if (t < shortest)
			hit = &data->object[i];
		i++;
	}
	data->camera.lookat = vect_add(\
	data->camera.pos, vect_scalar_mul(data->camera.ray, t));
	return (hit);
}
