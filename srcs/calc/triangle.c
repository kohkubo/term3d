#include "calc.h"

bool	is_intersect_with_sphere(t_camera *camera, t_vect pos, double radius)
{
	t_vect	d;
	double	t;

	d = vect_sub(camera->pos, pos);
	t = vect_dot(d, d) - radius * radius;
	if (t < 0)
		return (false);
	t = vect_dot(d, camera->ray) - sqrt(t);
	if (t < 0)
		return (false);
	camera->lookat = vect_add(camera->pos, vect_scalar_mul(camera->ray, t));
	return (true);
}

bool	is_intersect_with_vector(t_camera *camera, t_vect pos, t_vect edge)
{
	double	len;
	t_vect	normal;

	len = vect_len(edge);
	normal = vect_normalize(edge);
	if (len == 0)
		return (false);
	while (len > 0)
	{
		if (is_intersect_with_sphere(camera, pos, 0.5))
			return (true);
		pos = vect_move(pos, normal, 1);
		len -= 1;
	}
	return (false);
}

bool	is_intersect_with_triangle(t_camera *camera, t_object *triangle)
{
	t_vect	edge1;
	t_vect	edge2;
	t_vect	edge3;
	bool	ret1;
	bool	ret2;
	bool	ret3;

	edge1 = vect_sub(triangle->pos2, triangle->pos1);
	edge2 = vect_sub(triangle->pos3, triangle->pos1);
	edge3 = vect_sub(triangle->pos3, triangle->pos2);
	ret1 = is_intersect_with_vector(camera, triangle->pos1, edge1);
	ret2 = is_intersect_with_vector(camera, triangle->pos1, edge2);
	ret3 = is_intersect_with_vector(camera, triangle->pos2, edge3);
	//ret1 = is_intersect_with_sphere(camera, triangle->pos1, 0.8);
	//ret2 = is_intersect_with_sphere(camera, triangle->pos2, 0.8);
	//ret3 = is_intersect_with_sphere(camera, triangle->pos3, 0.8);
	return (ret1 || ret2 || ret3);
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

bool	is_intersect_with_triangle_sub(t_camera *camera,
									t_vect edge1,
									t_vect edge2,
									t_vect vect[2])
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
				camera->lookat = vect_add(camera->pos,
											vect_scalar_mul(vect_inv(vect[INV_RAY]),
													val[T]));
				return (true);
			}
		}
	}
	return (false);
}

bool	is_intersect_with_triangle_bk(t_camera *camera, t_object *triangle)
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
