#include "calc.h"

double solve_quadratic(double a, double b, double c)
{
	double d;
	double t;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	if (d == 0)
		return (-b / (2 * a));
	t = (-b - sqrt(d)) / (2 * a);
	return (t);
}

double intersect_with_sphere(t_camera *camera, t_vect pos, double radius)
{
	double a;
	double b;
	double c;
	t_vect s;
	t_vect d;

	// 目的地が第一引数、 スタート地点が第二位
	s = vect_sub(camera->pos, pos);
	d = camera->ray;
	a = vect_dot(d, d);
	b = 2 * vect_dot(s, d);
	c = vect_dot(s, s) - radius * radius;
	return solve_quadratic(a, b, c);
}

bool is_intersect_with_sphere(t_camera *camera, t_vect pos, double radius)
{
	double t;

	t = intersect_with_sphere(camera, pos, radius);
	if (t < 0)
		return (false);
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
		if (is_intersect_with_sphere(camera, pos, DOT_SIZE))
			return (true);
		pos = vect_move(pos, normal, DOT_DENSITY);
		len -= DOT_DENSITY;
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
