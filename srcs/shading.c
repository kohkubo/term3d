#include "shading.h"

double	diffuse_reflection(double intensity, t_vect *n, t_vect *l)
{
	return (intensity * fmax(vect_dot(*n, *l), 0));
}

double	specular_reflection(double intensity, t_vect *n, t_vect *l, t_vect *d)
{
	t_vect	v;
	t_vect	r;

	if (less(vect_dot(*n, *l), 0))
		return (0);
	v = vect_normalize(vect_inv(*d));
	r = vect_scalar_mul(*n, 2 * vect_dot(*n, *l));
	r = vect_normalize(vect_sub(r, *l));
	return (intensity * pow(fmax(vect_dot(v, r), 0), 8));
}

static char	get_density(double radiance)
{
	const char	*density = ".,:;-~+=!?*#$&@";

	if (less_equal(radiance, 0))
		return (' ');
	return (density[(int)(radiance * strlen(density))]);
}

static t_vect	get_triangle_normal(t_object *object)
{
	t_vect	p1;
	t_vect	p2;

	p1 = vect_sub(object->pos2, object->pos1);
	p2 = vect_sub(object->pos3, object->pos1);
	return (vect_normalize(vect_cross(p1, p2)));
}

char	shading(t_camera *camera, t_light *light, t_object *hit)
{
	t_vect	l;
	t_vect	n;
	double	rd;
	double	rs;

	l = vect_normalize(vect_sub(light->pos, camera->lookat));
	n = get_triangle_normal(hit);
	rd = diffuse_reflection(light->intensity, &n, &l);
	rs = specular_reflection(light->intensity, &n, &l, &camera->lookat);
	if (less_equal(1, rd + rs))
		return (get_density(0));
	return (get_density(rd + rs));
}
