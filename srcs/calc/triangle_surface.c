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

static double	intersect_with_triangle_surface_sub(\
t_camera *camera, t_vect edge1, t_vect edge2, t_vect vect[2])
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
				return (val[T]);
			}
		}
	}
	return (DBL_MAX);
}

double	intersect_with_triangle_surface(t_camera *camera, t_object *triangle)
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
	t = update_t(t, \
intersect_with_triangle_surface_sub(camera, edge1, edge2, vect));
	t = update_t(t, \
intersect_with_triangle_surface_sub(camera, edge2, edge1, vect));
	return (t);
}
