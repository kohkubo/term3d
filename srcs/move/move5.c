#include "move.h"

void	camera_stop(t_data *data)
{
	data->camera.rotate_angle = radian(!data->camera.rotate_angle);
}

void	camera_reset(t_data *data)
{
	data->camera.pos = \
	vect_add(vect_new(0, 0, -150), data->camera.center_object_pos);
	data->camera.up = vect_new(0, 1, 0);
	data->camera.right = vect_new(1, 0, 0);
	data->camera.normal = vect_new(0, 0, 1);
	data->camera.normal_axis = vect_normalize(vect_new(0, 1, 0));
	data->camera.rotate_angle = radian(1);
	data->light.pos = vect_new(150, 150, -150);
	data->light.intensity = 1.0;
}
