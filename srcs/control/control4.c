#include "control.h"

void	camera_rotate_speed_up(t_data *data)
{
	data->base_info.rotate_angle += ROTATE_SPEED;
}

void	camera_rotate_speed_down(t_data *data)
{
	data->base_info.rotate_angle -= ROTATE_SPEED;
}

void	camera_zoom_in(t_data *data)
{
	data->camera.pos = \
	vect_move(&data->camera.pos, &data->base_info.normal, MOVE_SCALE);
}

void	camera_zoom_out(t_data *data)
{
	data->camera.pos = \
	vect_move(&data->camera.pos, &data->base_info.normal, -MOVE_SCALE);
}
