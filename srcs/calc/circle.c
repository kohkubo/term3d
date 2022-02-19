#include "calc.h"

t_vect	intersect_with_plane(t_camera *camera, t_vect *center, t_vect *normal)
{
	t_vect	intersect_point;
	double	t;
	t_vect	ray;

	ray = vect_inv(camera->ray);
	if (is_right_angle(ray, *normal))
		return (vect_new(DBL_MAX, DBL_MAX, DBL_MAX));
	t = vect_dot(vect_sub(*center, camera->pos), *normal) / vect_dot(ray,
			*normal);
	if (t < 0)
		return (vect_new(DBL_MAX, DBL_MAX, DBL_MAX));
	intersect_point = vect_add(camera->pos, vect_scalar_mul(ray, t));
	return (intersect_point);
}

bool	is_intersect_with_circle(t_camera *camera, t_object *circle)
{
	double		distance;

	camera->lookat = intersect_with_plane(camera, &circle->pos1,
			&circle->normal);
	distance = vect_distance(camera->lookat, circle->pos1);
	if (less_equal(distance, circle->radius) && \
less_equal(circle->radius * 0.9, distance))
		return (true);
	return (false);
}
