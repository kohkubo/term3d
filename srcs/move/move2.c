#include "move.h"

void	camera_move_up(t_data *data)
{
	data->camera.pos = \
	vect_move(&data->camera.pos, &data->camera.up, MOVE_DISTANCE);
}

void	camera_move_down(t_data *data)
{
	data->camera.pos = \
	vect_move(&data->camera.pos, &data->camera.up, -MOVE_DISTANCE);
}

void	camera_move_left(t_data *data)
{
	data->camera.pos = \
	vect_move(&data->camera.pos, &data->camera.right, -MOVE_DISTANCE);
}

void	camera_move_right(t_data *data)
{
	data->camera.pos = \
	vect_move(&data->camera.pos, &data->camera.right, MOVE_DISTANCE);
}
