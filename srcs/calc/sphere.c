#include "calc.h"

static double	solve_quadratic(double a, double b, double c)
{
	double	d;
	double	t;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	if (d == 0)
		return (-b / (2 * a));
	t = (-b - sqrt(d)) / (2 * a);
	return (t);
}

// 目的地が第一引数、 スタート地点が第二位
// s = vect_sub(camera->pos, pos);
double	intersect_with_sphere(t_camera *camera, t_vect pos, double radius)
{
	double	a;
	double	b;
	double	c;
	t_vect	s;
	t_vect	d;

	s = vect_sub(camera->pos, pos);
	d = camera->ray;
	a = vect_dot(d, d);
	b = 2 * vect_dot(s, d);
	c = vect_dot(s, s) - radius * radius;
	return (solve_quadratic(a, b, c));
}
