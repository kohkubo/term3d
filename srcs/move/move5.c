#include "move.h"

void	camera_stop(t_data *data)
{
	data->base_info.rotate_angle = radian(!data->base_info.rotate_angle);
}

void	camera_reset(t_data *data)
{
	init_base_info(data);
}

void	light_move_front(t_data *data)
{
	data->light.pos = vect_new(0, 0, -1000);
}

void	light_move_back(t_data *data)
{
	data->light.pos = vect_new(0, 0, 1000);
}
