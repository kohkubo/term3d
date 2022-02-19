#include "calc.h"

bool	is_intersect_with_sphere(t_camera *camera, t_vect pos, double radius)
{
	t_vect	d;
	double	t;

	d = vect_sub(camera->pos, pos);
	t = vect_dot(d, d) - radius * radius;
	if (t < 0)
		return (false);
	t = vect_dot(d, camera->ray) - sqrt(t);
	if (t < 0)
		return (false);
	camera->lookat = vect_add(camera->pos, vect_scalar_mul(camera->ray, t));
	return (true);
}

bool	is_intersect_with_vector(t_camera *camera, t_vect pos, t_vect edge)
{
	double	len;
	t_vect	normal;

	len = vect_len(edge);
	normal = vect_normalize(edge);
	if (len == 0)
		return (false);
	while (len > 0)
	{
		if (is_intersect_with_sphere(camera, pos, 0.5))
			return (true);
		pos = vect_move(pos, normal, 1);
		len -= 1;
	}
	return (false);
}

#ifndef DOT

bool	is_intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	t_vect	edge[3];
	bool	ret[3];

	edge[0] = vect_sub(triangle->pos2, triangle->pos1);
	edge[1] = vect_sub(triangle->pos3, triangle->pos1);
	edge[2] = vect_sub(triangle->pos3, triangle->pos2);
	ret[0] = is_intersect_with_vector(camera, triangle->pos1, edge[0]);
	ret[1] = is_intersect_with_vector(camera, triangle->pos1, edge[1]);
	ret[2] = is_intersect_with_vector(camera, triangle->pos2, edge[2]);
	return (ret[0] || ret[1] || ret[2]);
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
