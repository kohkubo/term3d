#include "triangle.h"

static t_vect	triangle_normal(t_vect *edge1, t_vect *edge2)
{
	return (vect_cross(*edge1, *edge2));
}

/*
Tomas Mollerのアルゴリズムを使用している。
カリングが行われるため、この三角形には表と、描画されない裏が存在する。
*/
bool	is_intersect_with_triangle(t_camera *camera, t_triangle *triangle)
{
	t_vect	edge1;
	t_vect	edge2;
	double denominator;
	double u;
	double v;
	double t;

	edge1 = vect_sub(triangle->vect2, triangle->vect1);
	edge2 = vect_sub(triangle->vect3, triangle->vect1);
	denominator = vect_det(edge1, edge2, vect_inv(camera->ray));

	if (denominator <= 0)
		return (false);
	u = vect_det(vect_sub(camera->pos, triangle->vect1), edge2, vect_inv(camera->ray)) / denominator;
	if (u >= 0 && u <= 1)
	{
		v = vect_det(edge1, vect_sub(camera->pos, triangle->vect1), vect_inv(camera->ray)) / denominator;
		if (v >= 0 && (u + v <= 1))
		{
			t = vect_det(edge1, edge2, vect_sub(camera->pos, triangle->vect1)) / denominator;
			camera->lookat = vect_add(camera->pos, vect_scalar_mul(camera->ray, t));
			return (true);
		}
	}
	return false;
}
