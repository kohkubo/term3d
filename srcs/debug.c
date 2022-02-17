#include "debug.h"

void	print_circle_info(t_data *data)
{
	double	camera_to_circle;

	camera_to_circle = vect_distance(data->camera->pos, data->circle->center);
	printf("camera_to_circle: %f\n", camera_to_circle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("circle center");
	vect_print(data->circle->center);
}

void	print_triangle_info(t_data *data)
{
	double	camera_to_triangle;

	camera_to_triangle = vect_distance(data->camera->pos,
			data->triangle->vect1);
	printf("camera_to_triangle: %f\n", camera_to_triangle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("triangle a ");
	vect_print(data->triangle->vect1);
	printf("triangle b ");
	vect_print(data->triangle->vect2);
	printf("triangle c ");
	vect_print(data->triangle->vect3);
}
