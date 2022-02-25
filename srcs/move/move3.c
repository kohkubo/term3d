#include "move.h"

void	camera_rotate_up(t_data *data)
{
	data->base_info.normal_axis = vect_normalize(\
	vect_sub(&data->base_info.normal_axis, &data->base_info.right));
}

void	camera_rotate_down(t_data *data)
{
	data->base_info.normal_axis = vect_normalize(\
	vect_add(data->base_info.normal_axis, data->base_info.right));
}

void	camera_rotate_left(t_data *data)
{
	data->base_info.normal_axis = vect_normalize(\
	vect_sub(&data->base_info.normal_axis, &data->base_info.up));
}

void	camera_rotate_right(t_data *data)
{
	data->base_info.normal_axis = vect_normalize(\
	vect_add(data->base_info.normal_axis, data->base_info.up));
}
