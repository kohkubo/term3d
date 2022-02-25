#include "move.h"

void	camera_stop(t_data *data)
{
	data->base_info.rotate_angle = radian(!data->base_info.rotate_angle);
}

void	camera_reset(t_data *data)
{
	data->camera.pos = \
	vect_add(vect_new(0, 0, -150), data->base_info.center_object_pos);
	data->base_info.up = vect_new(0, 1, 0);
	data->base_info.right = vect_new(1, 0, 0);
	data->base_info.normal = vect_new(0, 0, 1);
	data->base_info.normal_axis = vect_normalize(vect_new(0, 1, 0));
	data->base_info.rotate_angle = radian(1);
	data->light.pos = vect_new(150, 150, -150);
	data->light.intensity = 1.0;
}
