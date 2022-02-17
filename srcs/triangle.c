#include "triangle.h"

enum {
	U,
	V,
	T,
	DET,
};

enum {
	P,
	VT,
	Q,
};

/*
Tomas Mollerのアルゴリズムを使用している。
カリングが行われるため、この三角形には表と、描画されない裏が存在する。
高速化とnorm対応のため非常に見にくくなってしまった。
*/
bool	is_intersect_with_triangle(t_camera *camera, t_triangle *triangle)
{
	t_vect	edge[2];
	t_vect	vect[3];
	double	vl[4];

	edge[0] = vect_sub(triangle->vert2, triangle->vert1);
	edge[1] = vect_sub(triangle->vert3, triangle->vert1);
	vect[P] = vect_cross(camera->ray, edge[1]);
	vl[DET] = vect_dot(vect[P], edge[0]);
	if (less_equal(vl[DET], 0))
		return (false);
	vect[VT] = vect_sub(camera->pos, triangle->vert1);
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

void	rotate_triangle(t_data *data)
{
	double	a;

	data->triangle->vert1 = vect_rotate(data->triangle->vert1, vect_new(0, 1,
				0), radian(2));
	data->triangle->vert2 = vect_rotate(data->triangle->vert2, vect_new(0, 1,
				0), radian(2));
	data->triangle->vert3 = vect_rotate(data->triangle->vert3, vect_new(0, 1,
				0), radian(2));
	a = vect_angle(data->triangle->vert2, vect_new(0, 0, 1));
	printf("angle: %f\n", degree(a));
}
