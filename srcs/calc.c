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

enum
{
	U,
	V,
	T,
	DET,
};

enum
{
	TRI_POS,
	INV_RAY,
};

bool	is_intersect_with_triangle_sub(t_camera *camera, \
t_vect edge1, t_vect edge2, t_vect vect[2])
{
	double	val[4];
	t_vect	d;

	val[DET] = vect_det(edge1, edge2, vect[INV_RAY]);
	if (0 < val[DET])
	{
		d = vect_sub(camera->pos, vect[TRI_POS]);
		val[U] = vect_det(d, edge2, vect[INV_RAY]) / val[DET];
		if (0 <= val[U] && val[U] <= 1)
		{
			val[V] = vect_det(edge1, d, vect[INV_RAY]) / val[DET];
			if ((0 <= val[V]) && (val[U] + val[V] <= 1))
			{
				val[T] = -vect_det(edge1, edge2, d) / val[DET];
				if (val[T] <= 0)
					return (false);
				camera->lookat = vect_add(camera->pos, \
vect_scalar_mul(camera->ray, val[T]));
				return (true);
			}
		}
	}
	return (false);
}

bool	is_intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	t_vect	edge1;
	t_vect	edge2;
	t_vect	vect[2];
	bool	ret1;
	bool	ret2;

	ret1 = false;
	ret2 = false;
	edge1 = vect_sub(triangle->pos2, triangle->pos1);
	edge2 = vect_sub(triangle->pos3, triangle->pos1);
	vect[TRI_POS] = triangle->pos1;
	vect[INV_RAY] = vect_inv(camera->ray);
	ret1 = is_intersect_with_triangle_sub(camera, edge1, edge2, vect);
	ret2 = is_intersect_with_triangle_sub(camera, edge2, edge1, vect);
	return (ret1 || ret2);
}
