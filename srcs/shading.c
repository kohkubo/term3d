#include "shading.h"

static double	diffuse_reflection(double intensity, t_vect *n, t_vect *l)
{
	return (KD * intensity * fmax(vect_dot(n, l), 0));
}

static double	specular_reflection(\
double intensity, t_vect *n, t_vect *l, t_vect *d)
{
	t_vect	v;
	t_vect	r;

	if (less(vect_dot(n, l), 0))
		return (0);
	v = vect_normalize(vect_inv(d));
	r = vect_scalar_mul(n, 2 * vect_dot(n, l));
	r = vect_normalize(vect_sub(&r, l));
	return (KS * intensity * pow(fmax(vect_dot(&v, &r), 0), SHININESS));
}

char	radiance_to_density(char *density, double radiance)
{
	if (radiance <= 0)
		return (' ');
	if (1 <= radiance)
		return (density[strlen(density)]);
	return (density[(int)(radiance * strlen(density))]);
}

double	shading(t_camera *camera, t_light *light, t_object *hit)
{
	t_vect	l;
	t_vect	n;
	double	ra;
	double	rd;
	double	rs;

	l = vect_normalize(vect_sub(&light->pos, &camera->lookat));
	n = hit->normal;
	if (less(vect_dot(&l, &n), 0))
		n = vect_inv(&n);
	ra = KA * IA;
	rd = diffuse_reflection(light->intensity, &n, &l);
	rs = specular_reflection(light->intensity, &n, &l, &camera->lookat);
	return (ra + rd + rs);
}
