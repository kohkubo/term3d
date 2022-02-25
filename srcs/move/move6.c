#include "move.h"

void	light_move_up(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.up, 50);
}

void	light_move_down(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.up, -50);
}

void	light_move_left(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.right, -50);
}

void	light_move_right(t_data *data)
{
	data->light.pos = \
	vect_move(&data->light.pos, &data->base_info.right, 50);
}
