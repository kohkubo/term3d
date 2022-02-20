#include "shading.h"

double	diffuse_reflection(double intensity, t_vect *l, t_vect *n)
{
	double	dot;

	dot = vect_dot(*n, *l);
	if (less(dot, 0.0))
		return (0);
	return (intensity * dot);
}

/*
double	specular_reflection(double ks, t_vect *l, t_vect *n,  t_vect *v)
{
	t_vect	r;

	if (less(vect_dot(*n, *l), 0))
		return (0);
	r = vect_sub(vect_scalar_mul(vect_scalar_mul(*n, vect_dot(*n, *l)), 2), *l);
	r = vect_normalize(r);
	if (less(vect_dot(r, *v), 0))
		return (0);
	return (ks * pow(vect_dot(r, *v), 8));
}
*/

char	get_depth(double radiance)
{
	char	*depth = ".,:;-~+=!?*#$&@";

	if (less_equal(radiance, 0))
		return (' ');
	return (depth[(int)(radiance * strlen(depth))]);
}

char	shading(t_vect *point, t_vect *normal)
{
	t_light	light;
	t_vect	l;
	double	rd;

	light.pos = vect_new(15, 15, -150);
	light.intensity = 1.0;
	l = vect_normalize(vect_sub(light.pos, *point));
	rd = diffuse_reflection(light.intensity, &l, normal);
	if (less_equal(1, rd))
		return (get_depth(0));
	return (get_depth(rd));
}
