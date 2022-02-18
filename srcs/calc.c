#include "calc.h"

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
	P,
	VT,
	Q,
};

/*
Tomas Mollerのアルゴリズムを使用している。
カリングが行われるため、この三角形には表と、描画されない裏が存在する。
高速化とnorm対応のため非常に見にくくなってしまった。
*/

bool	is_intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	t_vect		edge[2];
	t_vect		vect[3];
	double		vl[4];

	edge[0] = vect_sub(triangle->pos2, triangle->pos1);
	edge[1] = vect_sub(triangle->pos3, triangle->pos1);
	vect[P] = vect_cross(camera->ray, edge[1]);
	vl[DET] = vect_dot(vect[P], edge[0]);
	if (less_equal(vl[DET], 0))
		return (false);
	vect[VT] = vect_sub(camera->pos, triangle->pos1);
	vl[U] = vect_dot(vect[P], vect[VT]);
	if (less(vl[U], 0) || less(vl[DET], vl[U]))
		return (false);
	vect[Q] = vect_cross(vect[VT], edge[0]);
	vl[V] = vect_dot(vect[Q], camera->ray);
	if (less(vl[V], 0) || less(vl[DET], vl[U] + vl[V]))
		return (false);
	vl[T] = vect_dot(vect[Q], edge[1]) / vl[DET];
	camera->lookat = vect_add(camera->pos, vect_scalar_mul(camera->ray, vl[T]));
	return (true);
}

void	rotate_triangle(t_object *triangle)
{
	triangle->pos1 = vect_rotate(triangle->pos1, vect_new(0, 1, 0), radian(2));
	triangle->pos2 = vect_rotate(triangle->pos2, vect_new(0, 1, 0), radian(2));
	triangle->pos3 = vect_rotate(triangle->pos3, vect_new(0, 1, 0), radian(2));
}

void	rotate_circle(t_object *circle)
{
	circle->normal = vect_rotate(circle->normal, vect_new(0, 1, 0), radian(2));
}
