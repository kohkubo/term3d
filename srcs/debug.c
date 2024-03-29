#include "debug.h"

void	print_triangle_info(t_data *data)
{
	double	camera_to_lookat;

	printf("camera pos    ");
	vect_print(data->camera.pos);
	printf("camera normal ");
	vect_print(data->base_info.normal);
	camera_to_lookat = vect_distance(&data->camera.pos, &data->camera.lookat);
	printf("camera_to_lookat: %f\n", camera_to_lookat);
	printf("triangle a ");
	vect_print(data->object->pos1);
	printf("triangle b ");
	vect_print(data->object->pos2);
	printf("triangle c ");
	vect_print(data->object->pos3);
}

void	print_all_object_info(t_data *data)
{
	int	c;

	c = 0;
	printf("object count : %d\n", data->object_count);
	while (c < data->object_count)
	{
		printf("%-5d ", c + 1);
		printf("1: ");
		vect_print(data->object[c].pos1);
		printf("      ");
		printf("2: ");
		vect_print(data->object[c].pos2);
		printf("      ");
		printf("3: ");
		vect_print(data->object[c].pos3);
		c++;
	}
}
