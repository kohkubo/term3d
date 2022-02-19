#include "debug.h"

void	print_circle_info(t_data *data)
{
	double	camera_to_lookat;

	camera_to_lookat = vect_distance(data->camera.pos, data->camera.lookat);
	printf("camera_to_lookat: %f\n", camera_to_lookat);
	printf("camera pos");
	vect_print(data->camera.pos);
	printf("circle center");
	vect_print(data->object->pos1);
}

void	print_triangle_info(t_data *data)
{
	double	camera_to_lookat;

	printf("camera pos    ");
	vect_print(data->camera.pos);
	printf("camera normal ");
	vect_print(data->camera.normal);
	camera_to_lookat = vect_distance(data->camera.pos, data->camera.lookat);
	printf("camera_to_lookat: %f\n", camera_to_lookat);
	printf("triangle a ");
	vect_print(data->object->pos1);
	printf("triangle b ");
	vect_print(data->object->pos2);
	printf("triangle c ");
	vect_print(data->object->pos3);
}
