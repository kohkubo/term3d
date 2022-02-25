#include "ray.h"

t_object	*intersect(t_data *data)
{
	int			i;
	double		shortest;
	double		t;
	t_object	*hit;

	t = DBL_MAX;
	hit = NULL;
	i = 0;
	while (i < data->object_count)
	{
		shortest = t;
		t = fmin(t, data->intersect(&data->camera, &data->object[i]));
		if (t < shortest)
			hit = &data->object[i];
		i++;
	}
	data->camera.lookat = vect_add(\
	data->camera.pos, vect_scalar_mul(&data->camera.ray, t));
	return (hit);
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
	TMP,
	Q,
};

static double	intersect_with_triangle_surface_sub(
	t_camera *camera, t_vect *pos, t_vect *edge1, t_vect *edge2)
{
	double	val[4];
	t_vect	vect[3];

	vect[P] = vect_cross(camera->ray, *edge2);
	val[DET] = vect_dot(&vect[P], edge1);
	if (val[DET] > 0)
	{
		vect[TMP] = vect_sub(&camera->pos, pos);
		val[U] = vect_dot(&vect[P], &vect[TMP]);
		if ((val[U] >= 0) && (val[U] <= 1 * val[DET]))
		{
			vect[Q] = vect_cross(vect[TMP], *edge1);
			val[V] = vect_dot(&vect[Q], &camera->ray);
			if ((val[V] >= 0) && (val[U] + val[V] <= 1 * val[DET]))
			{
				val[T] = vect_dot(&vect[Q], edge2) / val[DET];
				if (val[T] >= 0)
					return (val[T]);
			}
		}
	}
	return (DBL_MAX);
}

double	intersect_with_triangle_surface(t_camera *camera, t_object *triangle)
{
	double	t;

	t = intersect_with_triangle_surface_sub(\
	camera, &triangle->pos1, &triangle->edge1, &triangle->edge2);
	t = fmin(t, intersect_with_triangle_surface_sub(\
	camera, &triangle->pos1, &triangle->edge2, &triangle->edge1));
	return (t);
}
