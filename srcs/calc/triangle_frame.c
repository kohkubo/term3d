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

	len = vect_len(&edge);
	normal = vect_normalize(edge);
	t = DBL_MAX;
	if (len == 0)
		return (t);
	while (len > 0)
	{
		t = update_t(t, intersect_with_sphere(camera, pos, DOT_SIZE));
		pos = vect_move(&pos, &normal, DOT_DENSITY);
		len -= DOT_DENSITY;
	}
	return (t);
}

double	intersect_with_triangle_frame(t_camera *camera, t_object *triangle)
{
	double	t;

	t = DBL_MAX;
	t = update_t(t, \
intersect_with_vector(camera, triangle->pos1, triangle->edge1));
	t = update_t(t, \
intersect_with_vector(camera, triangle->pos1, triangle->edge2));
	t = update_t(t, \
intersect_with_vector(camera, triangle->pos2, triangle->edge3));
	return (t);
}

double	intersect_with_triangle_dot(t_camera *camera, t_object *triangle)
{
	double	t;

	t = DBL_MAX;
	t = update_t(t, intersect_with_sphere(camera, triangle->pos1, DOT_SIZE));
	t = update_t(t, intersect_with_sphere(camera, triangle->pos2, DOT_SIZE));
	t = update_t(t, intersect_with_sphere(camera, triangle->pos3, DOT_SIZE));
	return (t);
}
