#include "debug.h"

void	print_circle_info(t_data *data)
{
	double	camera_to_circle;

	camera_to_circle = vect_distance(data->camera->pos, data->object->pos1);
	printf("camera_to_circle: %f\n", camera_to_circle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("circle center");
	vect_print(data->object->pos1);
}

void	print_triangle_info(t_data *data)
{
	double	camera_to_triangle;

	camera_to_triangle = vect_distance(data->camera->pos,
			data->object->pos1);
	printf("camera_to_triangle: %f\n", camera_to_triangle);
	printf("camera pos");
	vect_print(data->camera->pos);
	printf("triangle a ");
	vect_print(data->object->pos1);
	printf("triangle b ");
	vect_print(data->object->pos2);
	printf("triangle c ");
	vect_print(data->object->pos3);
}
