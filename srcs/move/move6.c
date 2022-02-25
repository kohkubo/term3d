#include "move.h"

void	light_move_up(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.up, MOVE_DISTANCE);
}

void	light_move_down(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.up, -MOVE_DISTANCE);
}

void	light_move_left(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.right, -MOVE_DISTANCE);
}

void	light_move_right(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.right, MOVE_DISTANCE);
}
