#include "move.h"

void	camera_rotate_up(t_data *data)
{
	data->camera.normal_axis = vect_normalize(\
	vect_sub(&data->camera.normal_axis, &data->camera.right));
}

void	camera_rotate_down(t_data *data)
{
	data->camera.normal_axis = vect_normalize(\
	vect_add(data->camera.normal_axis, data->camera.right));
}

void	camera_rotate_left(t_data *data)
{
	data->camera.normal_axis = vect_normalize(\
	vect_sub(&data->camera.normal_axis, &data->camera.up));
}

void	camera_rotate_right(t_data *data)
{
	data->camera.normal_axis = vect_normalize(\
	vect_add(data->camera.normal_axis, data->camera.up));
}
