#include "rotate.h"

static void	camera_rotate(t_data *data)
{
	data->camera.pos = vect_rotate(&data->camera.pos, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.normal = vect_rotate(&data->base_info.normal, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.up = vect_rotate(&data->base_info.up, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
	data->base_info.right = vect_rotate(&data->base_info.right, \
&data->base_info.axis_normal, data->base_info.rotate_angle);
}

void	rotate(t_data *data)
{
	if (data->base_info.rotate_angle == 0)
		return ;
	camera_rotate(data);
}
