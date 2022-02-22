#include "calc.h"

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

double	intersect_with_triangle_sub(t_camera *camera, t_vect edge1, t_vect edge2, t_vect vect[2])
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
				val[T] = vect_det(edge1, edge2, d) / val[DET];
				if (val[T] <= 0)
					return (DBL_MAX);
				//camera->lookat = vect_add(camera->pos, vect_scalar_mul(camera->ray, val[T]));
				return (val[T]);
			}
		}
	}
	return (DBL_MAX);
}

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

	len = vect_len(edge);
	normal = vect_normalize(edge);
	t = DBL_MAX;
	if (len == 0)
		return (t);
	while (len > 0)
	{
		t = update_t(t, intersect_with_sphere(camera, pos, DOT_SIZE));
		pos = vect_move(pos, normal, DOT_DENSITY);
		len -= DOT_DENSITY;
	}
	return (t);
}

#ifndef DOT

double	intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	t_vect	edge1;
	t_vect	edge2;
	t_vect	vect[2];
	double	t;

	t = DBL_MAX;
	edge1 = vect_sub(triangle->pos2, triangle->pos1);
	edge2 = vect_sub(triangle->pos3, triangle->pos1);
	vect[TRI_POS] = triangle->pos1;
	vect[INV_RAY] = vect_inv(camera->ray);
	t = update_t(t, intersect_with_triangle_sub(camera, edge1, edge2, vect));
	t = update_t(t, intersect_with_triangle_sub(camera, edge2, edge1, vect));
	return (t);
}

double	intersect_with_triangle2(t_camera *camera, t_object *triangle)
{
	t_vect	edge[3];
	double	t;

	edge[0] = vect_sub(triangle->pos2, triangle->pos1);
	edge[1] = vect_sub(triangle->pos3, triangle->pos1);
	edge[2] = vect_sub(triangle->pos3, triangle->pos2);
	t = DBL_MAX;
	t = update_t(t, intersect_with_vector(camera, triangle->pos1, edge[0]));
	t = update_t(t, intersect_with_vector(camera, triangle->pos1, edge[1]));
	t = update_t(t, intersect_with_vector(camera, triangle->pos2, edge[2]));
	return (t);
}

#else

bool	is_intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	bool	ret[3];

	ret[0] = is_intersect_with_sphere(camera, triangle->pos1, 0.8);
	ret[1] = is_intersect_with_sphere(camera, triangle->pos2, 0.8);
	ret[2] = is_intersect_with_sphere(camera, triangle->pos3, 0.8);
	return (ret[0] || ret[1] || ret[2]);
}

#endif
