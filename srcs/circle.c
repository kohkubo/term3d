#include "circle.h"

t_vect	intersect_with_plane(t_camera *camera, t_vect *center, t_vect *normal)
{
	t_vect	intersect_point;
	double	t;

	if (is_right_angle(camera->ray, *normal))
		return (vect_new(DBL_MAX, DBL_MAX, DBL_MAX));
	t = vect_dot(vect_sub(*center, camera->pos), *normal)
		/ vect_dot(camera->ray, *normal);
	if (t < 0)
		return (vect_new(DBL_MAX, DBL_MAX, DBL_MAX));
	intersect_point = vect_add(camera->pos, vect_scalar_mul(camera->ray, t));
	return (intersect_point);
}

bool	is_intersect_with_circle(t_camera *camera, t_circle *circle)
{
	double	distance;

	camera->lookat = intersect_with_plane(camera, &circle->center,
			&circle->normal);
	distance = vect_distance(camera->lookat, circle->center);
	if (less_equal(distance, circle->radius) && \
less_equal(circle->radius * 0.9, distance))
		return (true);
	return (false);
}
