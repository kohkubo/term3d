#include "shading.h"

enum
{
	N,
	L,
};

static double	diffuse_reflection(double intensity, double ln_dot)
{
	return (KD * intensity * ln_dot);
}

static double	specular_reflection(\
double intensity, t_vect vect[2], t_vect *d, double ln_dot)
{
	t_vect	v;
	t_vect	r;
	double	vr_dot;

	v = vect_inv(d);
	r = vect_scalar_mul(&vect[N], 2 * ln_dot);
	r = vect_normalize(vect_sub(&r, &vect[L]));
	vr_dot = vect_dot(&v, &r);
	if (vr_dot < 0)
		return (0);
	return (KS * intensity * pow(vr_dot, SHININESS));
}

char	radiance_to_density(t_config *conf, double radiance)
{
	if (radiance <= 0)
		return (' ');
	if (radiance >= 1)
		return (conf->charset[conf->charset_size]);
	return (conf->charset[(int)(radiance * conf->charset_size)]);
}

double	shading(t_camera *camera, t_light *light, t_object *hit)
{
	t_vect	vect[2];
	double	ln_dot;
	double	rd;
	double	rs;

	vect[L] = vect_normalize(vect_sub(&light->pos, &camera->lookat));
	vect[N] = hit->normal;
	ln_dot = vect_dot(&hit->normal, &vect[L]);
	if (ln_dot < 0)
		return (KA * IA);
	rd = diffuse_reflection(light->intensity, ln_dot);
	rs = specular_reflection(light->intensity, vect, &camera->lookat, ln_dot);
	return (KA * IA + rd + rs);
}
