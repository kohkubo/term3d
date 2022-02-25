#include "control.h"

void	light_move_up(t_data *data)
{
	data->light.pos = vect_new(0, MOVE_LIGHT, 0);
}

void	light_move_down(t_data *data)
{
	data->light.pos = vect_new(0, -MOVE_LIGHT, 0);
}

void	light_move_left(t_data *data)
{
	data->light.pos = vect_new(-MOVE_LIGHT, 0, 0);
}

void	light_move_right(t_data *data)
{
	data->light.pos = vect_new(MOVE_LIGHT, 0, 0);
}
