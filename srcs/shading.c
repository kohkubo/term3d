#include "shading.h"

enum
{
	N,
	L,
};

static double	diffuse_reflection(double intensity, double l_n_dot)
{
	return (KD * intensity * fmax(l_n_dot, 0));
}

static double	specular_reflection(\
double intensity, t_vect vect[2], t_vect *d, double l_n_dot)
{
	t_vect	v;
	t_vect	r;

	if (less(l_n_dot, 0))
		return (0);
	v = vect_normalize(vect_inv(d));
	r = vect_scalar_mul(&vect[N], 2 * l_n_dot);
	r = vect_normalize(vect_sub(&r, &vect[L]));
	return (KS * intensity * pow(fmax(vect_dot(&v, &r), 0), SHININESS));
}

char	radiance_to_density(t_config *conf, double radiance)
{
	if (radiance <= 0)
		return (' ');
	if (1 <= radiance)
		return (conf->charset[conf->charset_size]);
	return (conf->charset[(int)(radiance * conf->charset_size)]);
}

double	shading(t_camera *camera, t_light *light, t_object *hit)
{
	t_vect	vect[2];
	double	l_n_dot;
	double	rd;
	double	rs;

	vect[L] = vect_normalize(vect_sub(&light->pos, &camera->lookat));
	vect[N] = hit->normal;
	l_n_dot = vect_dot(&hit->normal, &vect[L]);
	if (less(l_n_dot, 0))
		vect[N] = vect_inv(&hit->normal);
	rd = diffuse_reflection(light->intensity, l_n_dot);
	rs = specular_reflection(light->intensity, vect, &camera->lookat, l_n_dot);
	return (KA * IA + rd + rs);
}
